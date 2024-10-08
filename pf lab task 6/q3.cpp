#include <stdio.h>
int main(){
	int num;
	do{
		printf("Enter a positive number:\n");
		scanf("%d", &num);
	}
	while(num<0);
	printf("Correct <%d>", num);
}