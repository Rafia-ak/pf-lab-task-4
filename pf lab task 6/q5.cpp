#include <stdio.h>
int main(){
	int num, index, prime;
	prime = 1;
	printf("Enter a number: ");
    scanf("%d", &num);
    if (num == 0 || num == 1){
        prime = 0;
    } 
	else {
        for (index = 2; index <= num/2; index = index+1){
            if (num % index == 0) {
                prime = 0;
                break;
        }
    }
    if (prime == 1)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.", num);
    }

}