#include <stdio.h>
int main(){
	int num, index, sum=0, array[20];
	for(index=0; index<=19; index++){
		printf("Enter value to add: ");
		scanf("%d", &num);
		array[index] = num;	
	}
	for(index=19; index>=0; index--){
		printf("%d ", array[index]);
	}
}