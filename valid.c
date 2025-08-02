#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "valid.h"
int valname(char* name) // validate name
{
    while(*name)
    {
        if(!(isalpha(*name)) && *name!=' ')
        {
        printf("Enter Correct Name..\n");
        return 0;
        }

        name++;
    }
    return 1;
}

int valmob(char *mob)                   //validate mobile
{
     int count=0;
    while(*mob)
    {

        if(!isdigit(*mob))
        {
            printf("Enter Correct Mobile Number..\n");
            return 0;
        }
        count++;
        mob++;

    }
    if(count!=10)//use strlen
    {
    printf("Enter 10 digit Mobile Number..\n");//10 digit num...
    return 0;
    }
    return 1;
}

int valemail(char *email)
{
    char *temp=email;

    if(isdigit(*email) || *email =='@' || *email=='.' || *email=='_')
    {
        printf("Enter valid Mail...\n");
        return 0;
    }
    int count_at=0,countdot=0;

    while(*email)
    {

        if(*email == '@')
        count_at++;
        if(*email =='.')
        countdot++;
        if(!isalpha(*email) && !isdigit(*email) && *email !='@' && *email !='.')
        {
            printf("Enter valid Mail...\n");
            return 0;
        }
        email++;

    }
    if(count_at!=1 || countdot !=1)
    {
        printf("Enter valid Mail...\n");
        return 0;
    }

    
    email=temp;
    while (*email)
    {
        if(*email=='@')
        {
            char *temp2=email+1;
            while(*temp2)
            {
                if(*temp2=='.')
                break;
                if(!isalpha(*temp2))
                {
                    printf("Enter valid Mail...\n");
                return 0;
                }
                temp2++;
            }
        
        //email++;
        
    }
    email++;
    }

    return  1;
}



void displayContact(AddressBook *addressBook,int i)
{       
        
        printf("%s ",addressBook->contacts[i].name);
        printf("%s ",addressBook->contacts[i].phone);
        printf("%s ",addressBook->contacts[i].email);
        printf("\n");
}


int bubblesort(AddressBook *addressBook,char name[])
{


}
int searchuniqueContact(AddressBook *addressBook,int search,char* content) 
{
    /* Define the logic for search */
    switch (search)
    {
        case 1:
      

        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].name,content)==0)
            {
                return  i;
            }
        }  break;
        case 2:
        
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].phone,content)==0)
            {
                return  i;
            }
        }  break;

        case 3:
        
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].email,content)==0)
            {
                return  i;
            }
        }  break;
        


    }   
return -1;
}

void tempuniquecreate(AddressBook *addressBook,int index,int choice)
{
    switch (choice)
    {
    case 1:
    char tname[20];
    while(1)
    {
    printf("Enter the Name of student :");      
    scanf(" %[^\n]",tname);
    if(valname(tname) && (searchuniqueContact(addressBook,1,tname)==-1))
    break;
    if(searchuniqueContact(addressBook,1,tname)!=-1)
    printf("--- Name of student already exists ---\n");
    }
    strcpy(addressBook->contacts[index].name,tname);
    break;

    case 2:
    char tphone[20];
    while(1)
    {
    printf("Enter the Phone of student :");      
    scanf(" %[^\n]",tphone);
    if(valmob(tphone) && (searchuniqueContact(addressBook,2,tphone)==-1))
    break;
    if(searchuniqueContact(addressBook,2,tphone)!=-1)
    printf("--- Phone of student already exists ---\n");
    }
    strcpy(addressBook->contacts[index].phone,tphone);
    break;

    case 3:
    char temail[20];
        while(1)
        {
        printf("Enter the Email of student :");
        
        scanf("%s",temail);
        if(valemail(temail) && (searchuniqueContact(addressBook,3,temail)==-1))
        break;
        if(searchuniqueContact(addressBook,3,temail)!=-1)
        printf("--- Email of student already exists ---\n");
        }
        strcpy(addressBook->contacts[index].email,temail);
        break;
        
    }
}
