#include <stdio.h>
#include <string.h>

void reverseString(char* str, int start, int end){
    if (start >= end){
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

int main(){
    char message[100];

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; 

    int length = strlen(message);

    reverseString(message, 0, length - 1);

    printf("Reversed Message: %s\n", message);

    return 0;
}
