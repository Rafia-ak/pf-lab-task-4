#include <stdio.h>

int main(){
	int arr[3][3];
	int i, j, sum;
	
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("Enter value for row %d: ", i+1);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	
	printf("Matrix: ");
	printf("\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			sum = sum + arr[i][j]; 
		}
		printf("Total score of participant %d: %d", i+1, sum);
		sum = 0;
		printf("\n");
	}
	
	printf("\n");
	
	for (j=0; j<3; j++){
		for (i=0; i<3; i++){
			sum = sum + arr[i][j]; 
		}
		printf("Total score of activity %d: %d", j+1, sum);
		sum = 0;
		printf("\n");
	}
	
}