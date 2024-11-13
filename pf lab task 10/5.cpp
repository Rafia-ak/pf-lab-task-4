#include <stdio.h>

int sumdigits(int number) {
	if (number == 0) {
        return 0;
    }
    return (number % 10) + sumdigits(number / 10);
	
}

int main() {
	int number;
	printf("Enter a number to sum its digits: ");
	scanf("%d", &number);
	int result = sumdigits(number);
    printf("Sum of digits of %d is %d.\n", number, result);
	
	return 0;
}