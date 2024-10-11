#include <stdio.h>
int main(){
	int num, index, sum=0, array[15];
	for(index=0; index<=14; index++){
		printf("Enter value to add: ");
		scanf("%d", &num);
		array[index] = num;
		sum = sum + num;
	}
	printf("Sum is: %d", sum);
	
}