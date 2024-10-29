#include <stdio.h>

int main(){
	int m1, n1, m2, n2;
	printf("Enter matrix 1 rows: ");
	scanf("%d", &m1);
	printf("Enter matrix 1 columns: ");
	scanf("%d", &n1);
	printf("Enter matrix 2 rows: ");
	scanf("%d", &m2);
	printf("Enter matrix 2 columns: ");
	scanf("%d", &n2);
	printf("\n");
	
	int matrix1[m1][n1];
	int matrix2[m2][n2];
	
	for (int i=0; i<m1; i++){
		for (int j=0; j<n1; j++){
			printf("Enter a value for matrix 1: ");
			scanf("%d", &matrix1[i][j]);
		}
	}
	printf("\n");
	
	for (int i=0; i<m2; i++){
		for (int j=0; j<n2; j++){
			printf("Enter a value for matrix 2: ");
			scanf("%d", &matrix2[i][j]);
		}
	}
	printf("\n");
	
	int sum[m1][n1];
			
	if (m1!=n1 || m2!=n2){
		printf("The matrices have different dimensions and hence cannot be added.");
		return 0;
	}
	else{
	    for (int i = 0; i < m1; i++){
       		for (int j = 0; j < n1; j++){
           		sum[i][j] = int(matrix1[i][j] + matrix2[i][j]);
           	}
        }	
    }

    printf("Sum of the matrices:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
    
}