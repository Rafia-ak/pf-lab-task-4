#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int *capacity, int value, int position) {
    if (*size == *capacity) {
        *capacity = (*capacity == 0) ? 1 : (*capacity * 2);
        int *temp = (int *)realloc(*arr, *capacity * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            free(*arr);
            exit(1);
        }
        *arr = temp;
    }
    for (int i = *size; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[position] = value;
    (*size)++;
}

void deleteElement(int **arr, int *size, int position) {
    if (*size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*size)--;
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int *arr = (int *)malloc(N * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        int size = 0, capacity = N;

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            size++;
        }

        int operations;
        scanf("%d", &operations);

        while (operations--) {
            int option, pos, value;
            scanf("%d", &option);

            if (option == 1) {
                scanf("%d %d", &value, &pos);
                pos--;
                if (pos < 0 || pos > size) {
                    printf("Invalid position\n");
                } else {
                    insert(&arr, &size, &capacity, value, pos);
                }
            } else if (option == 2) {
                scanf("%d", &pos);
                pos--;
                if (pos < 0 || pos >= size) {
                    printf("Invalid position\n");
                } else {
                    deleteElement(&arr, &size, pos);
                }
}

            display(arr, size);
        }

        free(arr);
    }

    return 0;
}
