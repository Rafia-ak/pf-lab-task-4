#include <stdio.h>

void bubbleSort(int array[], int n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (array[i] > array[i + 1]) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }

    bubbleSort(array, n - 1);
}

int main() {
    int array[100];
    int n;

    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);

    if (n > 100 || n < 1) {
        printf("Invalid array size. Please enter a number between 1 and 100.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
