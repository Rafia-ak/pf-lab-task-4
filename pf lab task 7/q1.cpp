#include <stdio.h>
int main(){
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
    int num, i, found = 0; 
    printf("Enter a number to search in the array: ");
    scanf("%d", &num);

    for (i=0; i<10; i++){
        if (array[i] == num){
            found = 1;
            break;
        }
    }
    if (found){
        printf("Number %d found at index %d.\n", num, i);
    } 
	else{
        printf("Number %d not found in the array.\n", num);
    }
}
