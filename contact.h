#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

// int valname(char* name);
// int valmob(char *mob);
// int valemail(char *email);


void createContact(AddressBook *addressBook);
void displayContact(AddressBook *addressBook,int );
int searchContact(AddressBook *addressBook,int );
void editContact(AddressBook *addressBook,int);
void deleteContact(AddressBook *addressBook,int);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

#endif
