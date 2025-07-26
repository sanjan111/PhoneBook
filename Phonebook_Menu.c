#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

// Structure created for Linked list
struct Contact
{
    int8 *name;
    int8 *phone_no;
    struct Contact *next;
};
// Using typedef to make alias for struct Contact
typedef struct Contact sContact;

// Global variables of struct Contact type.
sContact *first = NULL;
sContact *last = NULL;

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

void Phonebook_Add()
{
    printf("ADD CONTACT:\n");
    // Dynamically Allocating memory for newNode
    sContact *newNode = (sContact*) malloc(sizeof(sContact));  
    if (NULL == newNode)
    {
        printf("Memory not Allocated\n");
        return;
    }
     


}