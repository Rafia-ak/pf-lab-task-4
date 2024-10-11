#include <stdio.h>
int main(){
	int num, index, max, min, array[30];
	
	for(index=0; index<=29; index++){
		printf("Enter value to add: ");
		scanf("%d", &num);
		array[index] = num;	
	}
    
    max=min=array[0];
    
	for(index=0; index<=29; index++){
		if (array[index]>max){
			max=array[index];
		}
    }
	printf("Maximum number: %d\n", max);
	
	for(index=0; index<=29; index++){
		if (array[index]<min){
			min=array[index];
		}
	}
	printf("Minimum number: %d", min);
	
}
