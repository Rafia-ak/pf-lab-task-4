#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char line[1024];
    int lineNumber = 1;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    printf("\nContents of the file with line numbers:\n");
    printf("\n\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }

    fclose(file);
    return 0;
}
