#include <stdio.h>
#include <stdlib.h>

void makeEven(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            arr[i]--;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    makeEven(arr, n);

    printf("Modified array with only even numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
