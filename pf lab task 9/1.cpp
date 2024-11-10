#include <stdio.h>

void print_shape_A(int N){
    for (int i = 0; i <= N/2; i++){
        for (int j = 0; j < N/2 - i + 1; j++) printf(". ");
        for (int j = 0; j < i + 1; j++) printf("o");
        printf("\n");
    }
    for (int i = N/2 - 1; i >= 0; i--){
        for (int j = 0; j < N/2 - i + 1; j++) printf(". ");
        for (int j = 0; j < i + 1; j++) printf("o");
        printf("\n");
    }
}

int main(){
    int n, N;
    printf("Enter a Number: ");
    scanf("%d", &n);
    N = 2 * n + 1;
    print_shape_A(N);
    return 0;
}



