#include <stdio.h>
#include <stdlib.h>

void addNumber(float **arr, int *size, int *capacity, float num) {
    if (*size == *capacity) {
        *capacity *= 2;
        *arr = (float *)realloc(*arr, *capacity * sizeof(float));
        if (*arr == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
    (*arr)[*size] = num;
    (*size)++;
}

void displayNumbers(float *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Numbers in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void removeLastNumber(float **arr, int *size) {
    if (*size == 0) {
        printf("Array is empty.\n");
        return;
    }
    (*size)--;
}

int main() {
    int capacity = 4, size = 0;
    float *arr = (float *)malloc(capacity * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int choice;
    float num;

    do {
        printf("\nMenu:\n");
        printf("1. Add a new number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%f", &num);
                addNumber(&arr, &size, &capacity, num);
                break;
            case 2:
                displayNumbers(arr, size);
                break;
            case 3:
                removeLastNumber(&arr, &size);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    free(arr);
    return 0;
}
