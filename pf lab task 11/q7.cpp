#include <stdio.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_DEPARTMENTS 3
#define MAX_NAME_LEN 50

struct Course {
    char courseID[10];
    char courseName[MAX_NAME_LEN];
    char instructorName[MAX_NAME_LEN];
    int credits;
};

struct Department {
    char name[MAX_NAME_LEN];
    struct Course courses[MAX_COURSES];
    int numCourses;
};

struct University {
    struct Department departments[MAX_DEPARTMENTS];
    int numDepartments;
};

void addDepartment(struct University *uni) {
    if (uni->numDepartments < MAX_DEPARTMENTS) {
        printf("Enter department name: ");
        scanf(" %[^\n]", uni->departments[uni->numDepartments].name);
        uni->departments[uni->numDepartments].numCourses = 0;
        uni->numDepartments++;
        printf("Department added successfully!\n");
    } else {
        printf("Max departments reached!\n");
    }
}

void addCourse(struct University *uni) {
    char dept[MAX_NAME_LEN];
    printf("Enter department name: ");
    scanf(" %[^\n]", dept);

    for (int i = 0; i < uni->numDepartments; i++) {
        if (strcmp(uni->departments[i].name, dept) == 0) {
            if (uni->departments[i].numCourses < MAX_COURSES) {
                struct Course newCourse;
                printf("Enter course ID: ");
                scanf("%s", newCourse.courseID);
                printf("Enter course name: ");
                scanf(" %[^\n]", newCourse.courseName);
                printf("Enter instructor name: ");
                scanf(" %[^\n]", newCourse.instructorName);
                printf("Enter credits: ");
                scanf("%d", &newCourse.credits);
                uni->departments[i].courses[uni->departments[i].numCourses++] = newCourse;
                printf("Course added successfully!\n");
                return;
            } else {
                printf("Max courses reached for this department!\n");
                return;
            }
        }
    }
    printf("Department not found!\n");
}

void displayUniversity(struct University *uni) {
    if (uni->numDepartments == 0) {
        printf("No departments available.\n");
        return;
    }
    for (int i = 0; i < uni->numDepartments; i++) {
        printf("\nDepartment: %s\n", uni->departments[i].name);
        if (uni->departments[i].numCourses == 0) {
            printf("  No courses available in this department.\n");
        } else {
            for (int j = 0; j < uni->departments[i].numCourses; j++) {
                printf("  %s - %s by %s, Credits: %d\n", uni->departments[i].courses[j].courseID,
                       uni->departments[i].courses[j].courseName, uni->departments[i].courses[j].instructorName,
                       uni->departments[i].courses[j].credits);
            }
        }
    }
}

int calculateTotalCredits(struct University *uni, char *deptName) {
    for (int i = 0; i < uni->numDepartments; i++) {
        if (strcmp(uni->departments[i].name, deptName) == 0) {
            int totalCredits = 0;
            for (int j = 0; j < uni->departments[i].numCourses; j++) {
                totalCredits += uni->departments[i].courses[j].credits;
            }
            return totalCredits;
        }
    }
    return -1;
}

int main() {
    struct University uni = { .numDepartments = 0 };
    int choice;

    while (1) {
        printf("\n1. Add Department\n2. Add Course\n3. Display University\n4. Calculate Total Credits\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(&uni);
                break;
            case 2:
                addCourse(&uni);
                break;
            case 3:
                displayUniversity(&uni);
                break;
            case 4: {
                char dept[MAX_NAME_LEN];
                printf("Enter department name: ");
                scanf(" %[^\n]", dept);
                int credits = calculateTotalCredits(&uni, dept);
                if (credits != -1) {
                    printf("Total credits in %s: %d\n", dept, credits);
                } else {
                    printf("Department not found!\n");
                }
                break;
            }
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
