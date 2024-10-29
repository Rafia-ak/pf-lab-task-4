#include <stdio.h>

int main(){
    int num, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++){
        for (j = 0; j < i; j++){
            printf(" ");
        }
        for (j = num - i; j >= 1; j--){
            printf("%d ", j);
        }
        printf("\n");
    }

    for (i = 1; i < num; i++){
        for (j = 0; j < num - i - 1; j++){
            printf(" ");
        }
        for (j = i + 1; j >= 1; j--){
            printf("%d ", j);
        }
        printf("\n");
    }

}

