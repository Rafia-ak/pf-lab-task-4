#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j, modRow, modCol, newValue;
    int **array;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    array = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    printf("Enter the row index to modify (0 to %d): ", rows - 1);
    scanf("%d", &modRow);
    printf("Enter the column index to modify (0 to %d): ", cols - 1);
    scanf("%d", &modCol);

    if (modRow >= 0 && modRow < rows && modCol >= 0 && modCol < cols) {
        printf("Enter the new value for element [%d][%d]: ", modRow, modCol);
        scanf("%d", &newValue);
        array[modRow][modCol] = newValue;
    } else {
        printf("Invalid indices provided.\n");
    }

    printf("Modified array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
