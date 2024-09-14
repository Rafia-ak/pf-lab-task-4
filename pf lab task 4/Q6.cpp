#include <stdio.h>
int main(){
	int n1, n2;
	printf("Enter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	if (n1>n2){
		if (n1>100){
			printf("First number is significantly larger");
		}
		else{
			printf("First number is larger");
		}
    }
	else if (n1<n2){
		if (n1<0){
			printf("First number is negative and smaller");
		}
		else{
			printf("First number is smaller");
		}
    }
	else{
		printf("Both numbers are equal");
	}
}