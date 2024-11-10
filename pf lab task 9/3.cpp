#include <stdio.h>
#include <string.h>

int main(){
    char presetUsername[] = "admin";
    char presetPassword[] = "1234";

    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, presetUsername) == 0 && strcmp(password, presetPassword) == 0){
        printf("Access granted!\n");
    } 
	else{
        printf("Access denied!\n");
    }

    return 0;
}
