#include <stdio.h>
int main(){
	int num, index;
	printf("Enter an integer greater than or equal to 1: ");
	scanf("%d", &num);
	if (num<1){
		printf("Invalid. The number is less than 1.");
	}
	else{
		index=2;
		while (index<=num){
			printf("%d ", index);
			index=index+2;
		}
	}
}