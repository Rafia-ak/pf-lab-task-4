#include <stdio.h>
#include <string.h>

#define max 100

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
};

struct Car cars[max];
int count = 0;

void addCar() {
    if (count >= max) {
        printf("Car dealership inventory is full.\n");
        return;
    }

    printf("Enter car make: ");
    scanf("%s", cars[count].make);
    printf("Enter car model: ");
    scanf("%s", cars[count].model);
    printf("Enter car year: ");
    scanf("%d", &cars[count].year);
    printf("Enter car price: ");
    scanf("%f", &cars[count].price);
    printf("Enter car mileage: ");
    scanf("%d", &cars[count].mileage);

    count++;
    printf("Car added successfully.\n");
    printf("\n");
}

void displayCars() {
    if (count == 0) {
        printf("No cars available in the dealership.\n");
        return;
    }

    printf("List of Available Cars:\n");
    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: $%.2f\n", cars[i].price);
        printf("Mileage: %d miles\n", cars[i].mileage);
        printf("\n");
    }
}

void searchCar() {
    char searchMake[50], searchModel[50];
    printf("Enter make to search (or press enter to skip): ");
    scanf("%s", searchMake);
    printf("Enter model to search (or press enter to skip): ");
    scanf("%s", searchModel);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if ((strlen(searchMake) == 0 || strcmp(cars[i].make, searchMake) == 0) &&
            (strlen(searchModel) == 0 || strcmp(cars[i].model, searchModel) == 0)) {
            printf("Car %d:\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: $%.2f\n", cars[i].price);
            printf("Mileage: %d miles\n", cars[i].mileage);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No cars found with the specified make or model.\n");
    }
}

int main() {
    int choice;

    do {
        printf("Car Dealership System\n");
        printf("1. Add a New Car\n");
        printf("2. Display All Cars\n");
        printf("3. Search for Car by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                displayCars();
                break;
            case 3:
                searchCar();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


