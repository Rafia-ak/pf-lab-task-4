#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents, numGrades, **grades, *numGradesPerStudent;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    grades = (int **)malloc(numStudents * sizeof(int *));
    numGradesPerStudent = (int *)malloc(numStudents * sizeof(int));

    if (grades == NULL || numGradesPerStudent == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the number of grades for student %d: ", i + 1);
        scanf("%d", &numGradesPerStudent[i]);

        grades[i] = (int *)malloc(numGradesPerStudent[i] * sizeof(int));
        if (grades[i] == NULL) {
            printf("Memory allocation failed for student %d.\n", i + 1);
            return 1;
        }

        for (int j = 0; j < numGradesPerStudent[i]; j++) {
            printf("Enter grade %d for student %d: ", j + 1, i + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    printf("\nGrades for each student:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < numGradesPerStudent[i]; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);
    free(numGradesPerStudent);

    return 0;
}
