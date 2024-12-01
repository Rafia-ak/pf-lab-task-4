#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPoints, i;
    float *fees, totalProfit = 0.0;

    printf("Enter the total number of points: ");
    scanf("%d", &numPoints);

    if (numPoints <= 0) {
        printf("Invalid number of points! Must be greater than 0.\n");
        return 1;
    }

    fees = (float *)malloc(numPoints * sizeof(float));
    if (fees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the fee for each point:\n");
    for (i = 0; i < numPoints; i++) {
        printf("Fee for point %d: ", i + 1);
        scanf("%f", &fees[i]);

        if (fees[i] < 0) {
            printf("Negative fee detected. Setting fee for point %d to 0.\n", i + 1);
            fees[i] = 0;
        }

        totalProfit += fees[i];
    }

    printf("Total profit generated: %.2f\n", totalProfit);

    free(fees);

    return 0;
}
