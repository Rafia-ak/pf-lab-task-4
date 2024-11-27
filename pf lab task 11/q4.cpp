#include <stdio.h>
#include <string.h>

struct Employee {
    char name[100];
    char dob[15];
    int empID;
    char department[50];
    float salary;
};

void addEmployee(struct Employee *emp);
void deleteEmployee(struct Employee employees[], int *count, int empID);
void displayEmployees(struct Employee employees[], int count);

int main() {
    struct Employee employees[100];
    int count = 0, choice, empID;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(&employees[count]);
                count++;
                break;
            case 2:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &empID);
                deleteEmployee(employees, &count, empID);
                break;
            case 3:
                displayEmployees(employees, count);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void addEmployee(struct Employee *emp) {
    printf("Enter Name: ");
    getchar();
    fgets(emp->name, 100, stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0';

    printf("Enter Date of Birth (dd/mm/yyyy): ");
    fgets(emp->dob, 15, stdin);
    emp->dob[strcspn(emp->dob, "\n")] = '\0';

    printf("Enter Employee ID: ");
    scanf("%d", &emp->empID);

    printf("Enter Department: ");
    getchar();
    fgets(emp->department, 50, stdin);
    emp->department[strcspn(emp->department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp->salary);
}

void deleteEmployee(struct Employee employees[], int *count, int empID) {
    int i, found = 0;
    for (i = 0; i < *count; i++) {
        if (employees[i].empID == empID) {
            for (int j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            found = 1;
            printf("Employee with ID %d deleted successfully.\n", empID);
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
}

void displayEmployees(struct Employee employees[], int count) {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\nEmployee List:\n");
    for (int i = 0; i < count; i++) {
        printf("\nName: %s\n", employees[i].name);
        printf("Date of Birth: %s\n", employees[i].dob);
        printf("Employee ID: %d\n", employees[i].empID);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
    }
}
