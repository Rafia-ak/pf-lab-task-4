#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main() {
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    getchar();

    struct Employee employees[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter details for employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &employees[i].id);
        getchar();

        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);

        printf("Department: ");
        fgets(employees[i].department, sizeof(employees[i].department), stdin);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        getchar();
    }

    printf("\n--- Employee Details ---\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\n-Employee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s", employees[i].name);
        printf("Department: %s", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    return 0;
}
