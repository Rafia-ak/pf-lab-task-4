#include <stdio.h>

int main(){
	int arr[4][4];
	int i, j, sum;
	
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("Enter marks for student %d: ", i+1);
			scanf("%d", &arr[i][j]);
		}
	}
	
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if (arr[i][j] < 0){
				arr[i][j] = 0;
			}
		}
	}
	
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}