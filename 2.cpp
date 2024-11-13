#include <stdio.h>

void printPercentage(int number, int percent){
    if (percent > 100) {
        return;
    }
    printf("%d%% of %d: %.2f\n", percent, number, number * (percent / 100.0)); 
    printPercentage(number, percent + 1); 
}

int main(){
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printPercentage(number, 1);

    return 0;
}
