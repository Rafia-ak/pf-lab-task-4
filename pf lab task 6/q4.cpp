
#include <stdio.h>
int main(){
	float num, sum;
	sum = 0;
	printf("Enter a value: ");
	scanf("%f", &num);
	while (num != 0){
		sum = sum + num;
		printf("Enter a value: ");
	    scanf("%f", &num);	
	}
	printf("Sum is: %f", sum);
}