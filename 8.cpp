#include <stdio.h>

void printArray(int array[], int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", array[0]);
    printArray(array + 1, n - 1);
}

int main() {
    int array[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array elements: ");
    printArray(array, n);
    printf("\n");

    return 0;
}
