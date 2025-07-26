#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

// Structure created for Linked list
struct Contact
{
    int8 name[50];
    int8 phone_no[20];
    struct Contact *next;
};
// Using typedef to make alias for struct Contact
typedef struct Contact sContact;

// Global variables of struct Contact type.
sContact *first = NULL;
sContact *last = NULL;

void removeNewline(char *str);
void Phonebook_Add();


// Function definition of Menu( which contains evrything on phonebook(like main.c for phonebook))
void Phonebook_Menu()
{
    while (1)
    {
        uint8 choose;
        printf("MENU:\n\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contacts\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Choose the option: ");
        scanf("%d",&choose);
        getchar();
        printf("\n");


        switch (choose)
        {
            case 1:
                Phonebook_Add();
                break;
            case 2:
                //Phonebook_Delete();
                break;
            case 3:
            // Phonebook_Search();
                break;
            case 4:
                //Phonebook_Display();
                break;
            default:
                printf("Exiting...\n");// deliberate choice (Exiting on any number than 1 to 4)
                return;
        }
    }
}
void removeNewline(char *str)
{
    str[strcspn(str,"\n")] = '\0';
}

void Phonebook_Add()
{
    printf("ADD CONTACT:\n");
    int8 nm[50],ph_no[20];
    //Taking user Input:
    printf("Enter Name:\n");
    fgets(nm,50,stdin);
    removeNewline(nm);
    printf("Enter Phone No:\n");
    scanf("%s",&ph_no);//check
    // Dynamically Allocating memory for newNode
    sContact *newNode = (sContact*) malloc(sizeof(sContact));  
    if (NULL == newNode)
    {
        printf("Memory not Allocated\n");
        return;
    }
    // copying the name and phone no to the newNode
    strcpy(newNode->name, nm);
    strcpy(newNode->phone_no,ph_no);
    //Set newNode next to NULL
    newNode -> next = NULL;
    // if List is Empty
    if (NULL == first)
    {
        first = newNode;
        printf("Contact Added Successfully\n");
        return;
    }
    //if list is not empty, do string comparision,to check whether new Node comes before first
    if (strcmp(newNode -> name, first -> name) < 0)
    {
        newNode ->next = first;
        first = newNode;
        printf("Contact Added Successfully\n");
        return;
    }
    
    
     


}