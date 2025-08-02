#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "valid.h"



void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    printf("Contacts..\n");

    // switch (sortCriteria)
    // {
    //     case 1:
    //     bubblesort(addressBook,addressBook->contacts->name);

    for(int i = 0; i < addressBook->contactCount; i++)
    displayContact(addressBook,i);
    
    // }   
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}



void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("***Creating New Contact***\n");
    for(int i=addressBook->contactCount;i<addressBook->contactCount+1;i++)
    {
        // name :
        // if(searchContact(addressBook,1) ==-1)
        tempuniquecreate(addressBook,i,1);
        // else
        // {
        // printf("!!! Enter different name !!!\n");
        // goto name;
        //}
        phone :
        // if(searchContact(addressBook,1) ==-1)
        tempuniquecreate(addressBook,i,2);
        // else
        // {
        // printf("!!! Enter different phone !!!\n");
        // goto phone;
        // }

        // email :
        // if(searchContact(addressBook,1) ==-1)
         tempuniquecreate(addressBook,i,3);
        // else
        // {
        // printf("!!! Enter different email !!!\n");
        // goto email;
        //}
    }
   
    addressBook->contactCount++;
    
    printf("***Contact Created Successfully***");
}


int searchContact(AddressBook *addressBook,int search) 
{
    /* Define the logic for search */
    switch (search)
    {
        case 1:
       char  tname[20];
        while(1)
        {
        printf("Enter the Name of student :");
        
        scanf(" %[^\n]",tname);
        if(valname(tname))
        break;
        }



        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].name,tname)==0)
            {
                return  i;
            }
        }  break;
        case 2:
        char tphone[20];
        while(1)
        {
        printf("Enter the Phone of student :");
        
        scanf("%s",tphone);
        if(valmob(tphone))
        break;
        }
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].phone,tphone)==0)
            {
                return  i;
            }
        }  break;

        case 3:
        char temail[20];
        while(1)
        {
        printf("Enter the email of student :");
        
        scanf("%s",temail);
        if(valemail(temail))
        break;
        }
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,temail)==0)
            {
                return  i;
            }
        }  break;
        default:
        printf("!!! Enter valid choice !!!");


    }   
return -1;
}

void editContact(AddressBook *addressBook,int index)
{
	/* Define the logic for Editcontact */
    int choice;
    displayContact(addressBook,index);
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. ALL\n");
    printf("Enter the choice to edit contact :");
    scanf("%d",&choice);
    printf("***Editing Contact***\n");
    
    switch (choice)
    {
        case 1:
        tempuniquecreate(addressBook,index,1);
        break;

        case 2:
        tempuniquecreate(addressBook,index,2);
        break;

        case 3:
        tempuniquecreate(addressBook,index,3);
        break;

        case 4:
        tempuniquecreate(addressBook,index,1);
        tempuniquecreate(addressBook,index,2);
        tempuniquecreate(addressBook,index,3);
        break;
        
        default:
        printf("!!! Enter valid choice !!!");



    }
    printf("***Edit Done Successfully***");
    
}

void deleteContact(AddressBook *addressBook,int index)
{
	/* Define the logic for deletecontact */
    displayContact(addressBook,index);
    printf("Are you sure you want to delete contact? (y/n)\n");
    char choice;
    scanf(" %c",&choice);
    if(choice=='y')
    {
        printf("***Contact deleted successfully***\n");
        for(int i=index;i<addressBook->contactCount;i++)
        {
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        addressBook->contactCount--;
    } 
    else
    printf("***Aborting deletion***\n");
}

// void displayContact(AddressBook *addressBook,int i)
// {       
//         printf("Contacts..\n");
//         printf("%s ",addressBook->contacts[i].name);
//         printf("%s ",addressBook->contacts[i].phone);
//         printf("%s ",addressBook->contacts[i].email);
//         printf("\n");
// }





