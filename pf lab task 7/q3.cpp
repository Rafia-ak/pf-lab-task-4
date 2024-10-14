#include <stdio.h>
int main(){
    int array[12], array2[6];
    int i, x, num, temp;
    for (i=0; i<12; i++){
	    printf("Enter a number to add in the array: ");
        scanf("%d", &num);
        array[i] = num;
    }
    printf("Input array: ");
    for (i=0; i<12; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    for (i=0, x=0; i<12; i=i+2, x++){
    	array2[x]= array[i] + array[i+1];
    	}
    	
    printf("Pair sum array: ");
    for (x=0; x<6; x++) {
        printf("%d ", array2[x]);
    }
    printf("\n");
}