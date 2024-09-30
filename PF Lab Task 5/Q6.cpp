#include <stdio.h>
int main(){
	int num;
	int count = 0;
	printf("Enter your integer upto 255: ");
	scanf("%d", &num);
	if (num < 0 || num > 255) {
        printf("Please enter a number between 0 and 255.\n");
    }
    else{
	   if (num & 1) count++;
       if (num & 2) count++;
       if (num & 4) count++;
       if (num & 8) count++;
       if (num & 16) count++;
       if (num & 32) count++;
       if (num & 64) count++;
       if (num & 128) count++;
       printf("The number of 1s in the binary representation of %d is: %d\n", num, count);
    }
}