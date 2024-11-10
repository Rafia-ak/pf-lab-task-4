#include <stdio.h>

int main(){
    int bolts, nuts, washers;
    int totalCost;

    printf("Number of bolts: ");
    scanf("%d", &bolts);
    printf("Number of nuts: ");
    scanf("%d", &nuts);
    printf("Number of washers: ");
    scanf("%d", &washers);

    totalCost = (bolts * 5) + (nuts * 3) + (washers * 1);

    int isValidOrder = 1;
    if (nuts < bolts){
        printf("Check the Order: too few nuts\n");
        isValidOrder = 0;
    }
    if (washers < 2 * bolts){
        printf("Check the Order: too few washers\n");
        isValidOrder = 0;
    }
    
    if (isValidOrder){
        printf("Order is OK.\n");
    }

    printf("Total cost: %d\n", totalCost);

    return 0;
}
