#include <stdio.h>
#include "contact.h"
#include <ctype.h>

int main() {
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                printf("Select Search criteria:\n");
                printf("1. Search by name\n");
                printf("2. Search by phone\n");
                printf("3. Search by email\n");
                printf("Enter your choice: ");
                int searchChoice;
                scanf("%d", &searchChoice);
                int index= searchContact(&addressBook,searchChoice);
                if(index ==-1)
                printf("\nContact not found\n");
                else
                {printf("Contacts..\n");
                displayContact(&addressBook, index);}
                
                break;
            case 3:
                printf("Select Edit criteria:\n");
                printf("1. Edit by name\n");
                printf("2. Edit by phone\n");
                printf("3. Edit by email\n");
                //printf("4. Edit name,phone,email\n");
                printf("Enter your choice: ");
                int editChoice;
                scanf("%d", &editChoice);
                int editsearch_return= searchContact(&addressBook,editChoice);
                if(editsearch_return ==-1)
                printf("\nContact not found\n");
                else
                editContact(&addressBook,editsearch_return);
                break;
                
            case 4:
                printf("Select Delete criteria:\n");
                printf("1. Delete by name\n");
                printf("2. Delete by phone\n");
                printf("3. Delete by email\n");
                printf("Enter your choice: ");
                int deleteChoice;
                scanf("%d", &deleteChoice);
                int deletesearch_return= searchContact(&addressBook,deleteChoice);
                if(deletesearch_return ==-1)
                printf("Contact not found\n");
                else
                deleteContact(&addressBook,deletesearch_return);
                break;
            case 5:
                printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf("%d", &sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                //saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
       return 0;
}
