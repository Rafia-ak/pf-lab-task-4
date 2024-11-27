#include <stdio.h>
#include <string.h>

struct Invoice {
    char partNumber[50];
    char partDescription[100];
    int quantity;
    float pricePerItem;
};

float calculateInvoiceAmount(struct Invoice inv) {
    if (inv.quantity < 0) {
        inv.quantity = 0;
    }
    if (inv.pricePerItem < 0) {
        inv.pricePerItem = 0;
    }
    return inv.quantity * inv.pricePerItem;
}

int main() {
    struct Invoice inv;

    printf("Enter part number: ");
    scanf("%s", inv.partNumber);

    printf("Enter part description: ");
    scanf(" %[^\n]", inv.partDescription);

    printf("Enter quantity: ");
    scanf("%d", &inv.quantity);

    printf("Enter price per item: ");
    scanf("%f", &inv.pricePerItem);

    printf("\nPart Number: %s\n", inv.partNumber);
    printf("Part Description: %s\n", inv.partDescription);
    printf("Quantity: %d\n", inv.quantity);
    printf("Price per Item: %.2f\n", inv.pricePerItem);
    printf("Invoice Amount: %.2f\n", calculateInvoiceAmount(inv));

    return 0;
}
