#include <stdio.h>
#include <string.h>

void reverseString(char *string, int start, int end) {
    if (start >= end) {
        return;
    }

    char temp = string[start];
    string[start] = string[end];
    string[end] = temp;

    reverseString(string, start + 1, end - 1);
}

int main() {
    char string[100];
    printf("Enter a string to reverse it: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    
    reverseString(string, 0, strlen(string) - 1);
    printf("Reversed string: %s\n", string);
    
    return 0;
}
