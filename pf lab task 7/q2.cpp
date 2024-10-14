#include <stdio.h>
int main(){
    int array[10];
    int i, num, temp;
    for (i=0; i<10; i++){
	    printf("Enter a number to add in the array: ");
        scanf("%d", &num);
        array[i] = num;
    }
    printf("Before: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    temp = array[0];
    for (i=0; i<9; i++){
    	array[i]=array[i+1];
	}
	array[9]=temp;
	
	printf("After: ");
	for (i=0; i<10; i++) {
        printf("%d ", array[i]);
    }
}
