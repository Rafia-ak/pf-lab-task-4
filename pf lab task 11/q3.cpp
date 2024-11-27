#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *filec;
	FILE *filep;
    char filecopy[100];
	char filepaste[100];
    int ch;

    printf("Enter the filename to copy data: ");
    scanf("%s", filecopy);
    filec = fopen(filecopy, "r");
    
    if (filec == NULL) {
        printf("Could not open file %s\n", filec);
        return 1;
    }
    
    printf("Enter the filename to paste data: ");
    scanf("%s", filepaste);
    filep = fopen(filepaste, "w");
    
    if (filep == NULL) {
        printf("Could not open file %s\n", filep);
        fclose(filec);
        return 1;
    }
    
    while ((ch = fgetc(filec)) != EOF) {
    	if (islower(ch)) {
        	ch = toupper(ch);
    	}
    fputc(ch, filep);
	}

	fclose(filec);
	fclose(filep);

	printf("Data copied successfully from %s to %s with lowercase converted to uppercase.\n", filecopy, filepaste);

	return 0;
}
    
    
    
    
    
    
    
    
    
    
    