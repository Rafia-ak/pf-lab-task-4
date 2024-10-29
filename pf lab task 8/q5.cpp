#include <stdio.h>
int main(){
	int arr[4][4];
	int i, j, temp;
	
	printf("Enter the scores for the teams (4x4 matrix):\n");
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("Enter score for Team %d, Round %d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
	printf("\n");
	
	for (j = 0; j < 3; j++){
    	for (i = 0; i < 3 - 1; i++){
        	for (int k = i + 1; k < 3; k++){
            	if (arr[i][j] > arr[k][j]){
                	temp = arr[i][j];
                	arr[i][j] = arr[k][j];
                	arr[k][j] = temp;
            	}
        	}
    	}
	}
	
	printf("\nSorted Scores:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
		
		
	}
	
}