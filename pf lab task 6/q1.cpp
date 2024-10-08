#include <stdio.h>
int main(){
	int num, index, factorial;
	printf("Enter a positive integer: ");
	scanf("%d", &num);
	if (num<0){
		printf("Negative input. Enter a positive integer.");
	}
	else{
		for (index=1, factorial=1; index<=num; index++){
			factorial = factorial * index;
		}
		printf("Factorial of %d is %d.", num, factorial);	
	}
}
