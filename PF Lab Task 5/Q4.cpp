#include <stdio.h>
int main(){
	char member;
	float amount;
	printf("Enter your purchase amount in dollars: ");
	scanf("%f", &amount);
    printf("Do you have membership? Y/N: ");
    scanf(" %c", &member);
	amount > 100 && member == 'Y' ? printf("Discount applies") : printf("Discount doesn't apply");	
	
}