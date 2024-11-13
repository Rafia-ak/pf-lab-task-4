#include <stdio.h>
#include <string.h>

#define max 100

struct TravelPackage {
    char name[50];
    char destination[50];
    int duration;
    float cost;
    int seatsAvailable;
};

struct TravelPackage packages[max];
int packageCount = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addPackage() {
    if (packageCount >= max) {
        printf("No more packages can be added.\n");
        return;
    }

    printf("Enter package name: ");
    clearInputBuffer();
    fgets(packages[packageCount].name, sizeof(packages[packageCount].name), stdin);
    packages[packageCount].name[strcspn(packages[packageCount].name, "\n")] = '\0';

    printf("Enter destination: ");
    fgets(packages[packageCount].destination, sizeof(packages[packageCount].destination), stdin);
    packages[packageCount].destination[strcspn(packages[packageCount].destination, "\n")] = '\0';

    printf("Enter duration (in days): ");
    while (scanf("%d", &packages[packageCount].duration) != 1 || packages[packageCount].duration <= 0) {
        printf("Invalid input. Please enter a positive integer for duration: ");
        clearInputBuffer();
    }

    printf("Enter cost per person: ");
    while (scanf("%f", &packages[packageCount].cost) != 1 || packages[packageCount].cost <= 0) {
        printf("Invalid input. Please enter a positive number for cost: ");
        clearInputBuffer();
    }

    printf("Enter number of seats available: ");
    while (scanf("%d", &packages[packageCount].seatsAvailable) != 1 || packages[packageCount].seatsAvailable < 0) {
        printf("Invalid input. Please enter a non-negative integer for seats: ");
        clearInputBuffer();
    }

    packageCount++;
    printf("Package added successfully.\n");
}

void displayPackages() {
    if (packageCount == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("Available Travel Packages:\n");
    for (int i = 0; i < packageCount; i++) {
        printf("Package %d:\n", i + 1);
        printf("Name: %s\n", packages[i].name);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f per person\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
        printf("\n");
    }
}

void bookPackage() {
    int packageNumber, seatsToBook;

    if (packageCount == 0) {
        printf("No packages available for booking.\n");
        return;
    }

    displayPackages();
    printf("Enter the package number you want to book: ");
    while (scanf("%d", &packageNumber) != 1 || packageNumber < 1 || packageNumber > packageCount) {
        printf("Invalid package number. Please enter a valid number (1-%d): ", packageCount);
        clearInputBuffer();
    }

    printf("Enter number of seats to book: ");
    while (scanf("%d", &seatsToBook) != 1 || seatsToBook <= 0 || seatsToBook > packages[packageNumber - 1].seatsAvailable) {
        printf("Invalid input. Please enter a valid number of seats to book (1-%d): ", packages[packageNumber - 1].seatsAvailable);
        clearInputBuffer();
    }

    packages[packageNumber - 1].seatsAvailable -= seatsToBook;
    printf("Booking successful! You booked %d seats for Package %d.\n", seatsToBook, packageNumber);
}

int main() {
    int choice;

    do {
        printf("Travel Package System\n");
        printf("1. Add a New Package\n");
        printf("2. Display All Packages\n");
        printf("3. Book a Package\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid choice. Please enter a number between 1 and 4: ");
            clearInputBuffer();
        }

        switch (choice) {
            case 1:
                addPackage();
                break;
            case 2:
                displayPackages();
                break;
            case 3:
                bookPackage();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
