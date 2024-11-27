#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100
#define FILENAME "books.txt"

struct Book {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int quantity;
    float price;
};

void addBook() {
    FILE *file = fopen(FILENAME, "a+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);

    struct Book temp;
    while (fread(&temp, sizeof(struct Book), 1, file)) {
        if (temp.id == newBook.id) {
            printf("Book ID already exists.\n");
            fclose(file);
            return;
        }
    }

    printf("Enter Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);
    if (newBook.quantity < 0) newBook.quantity = 0;
    printf("Enter Price: ");
    scanf("%f", &newBook.price);
    if (newBook.price < 0) newBook.price = 0;

    fwrite(&newBook, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book added successfully.\n");
}

void viewBooks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file or no records found.\n");
        return;
    }
    struct Book book;
    printf("\nBooks in Library:\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("\nBook ID: %d\n", book.id);
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Quantity: %d\n", book.quantity);
        printf("Price: %.2f\n", book.price);
    }
    fclose(file);
}

void searchBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file or no records found.\n");
        return;
    }
    int choice, id;
    char title[MAX_TITLE_LEN];
    printf("Search by: 1. ID 2. Title: ");
    scanf("%d", &choice);

    struct Book book;
    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (book.id == id) {
                printf("\nBook Found:\n");
                printf("Book ID: %d\n", book.id);
                printf("Title: %s\n", book.title);
                printf("Author: %s\n", book.author);
                printf("Quantity: %d\n", book.quantity);
                printf("Price: %.2f\n", book.price);
                fclose(file);
                return;
            }
        }
    } else if (choice == 2) {
        printf("Enter Title: ");
        scanf(" %[^\n]", title);
        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (strcmp(book.title, title) == 0) {
                printf("\nBook Found:\n");
                printf("Book ID: %d\n", book.id);
                printf("Title: %s\n", book.title);
                printf("Author: %s\n", book.author);
                printf("Quantity: %d\n", book.quantity);
                printf("Price: %.2f\n", book.price);
                fclose(file);
                return;
            }
        }
    }
    printf("Book not found.\n");
    fclose(file);
}

void updateBook() {
    FILE *file = fopen(FILENAME, "rb+");
    if (!file) {
        printf("Error opening file or no records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    struct Book book;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            found = 1;

            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            if (book.quantity < 0) book.quantity = 0;

            printf("Enter new Price: ");
            scanf("%f", &book.price);
            if (book.price < 0) book.price = 0;

            fseek(file, -(long)sizeof(struct Book), SEEK_CUR);
            if (fwrite(&book, sizeof(struct Book), 1, file) != 1) {
                printf("Error writing updated record.\n");
            } else {
                printf("Book updated successfully.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book ID not found.\n");
    }

    fclose(file);
}

void deleteBook() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file or no records found.\n");
        return;
    }
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        fclose(file);
        printf("Error creating temporary file.\n");
        return;
    }
    int id, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    struct Book book;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id != id) {
            fwrite(&book, sizeof(struct Book), 1, tempFile);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book ID not found.\n");
    }
}

void calculateInventoryValue() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file or no records found.\n");
        return;
    }
    struct Book book;
    float totalValue = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        totalValue += book.quantity * book.price;
    }
    fclose(file);
    printf("Total Inventory Value: %.2f\n", totalValue);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. View All Books\n3. Search Book\n4. Update Book\n5. Delete Book\n");
        printf("6. Calculate Inventory Value\n7. Exit\n Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) addBook();
        else if (choice == 2) viewBooks();
        else if (choice == 3) searchBook();
        else if (choice == 4) updateBook();
        else if (choice == 5) deleteBook();
        else if (choice == 6) calculateInventoryValue();
        else if (choice == 7) break;
        else printf("Invalid choice. Try again.\n");
    }
    return 0;
}
