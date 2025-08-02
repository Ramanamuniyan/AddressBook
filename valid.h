#ifndef VALID_H
#define VALID_H


#include "contact.h"
int searchuniqueContact(AddressBook *addressBook,int search,char* content);
void tempuniquecreate(AddressBook *addressBook,int index,int choice);
void temp(AddressBook *addressBook,int,int);
int valname(char* name);
int valmob(char *mob);
int valemail(char *email);




#endif