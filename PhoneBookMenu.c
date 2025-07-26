#include "PhoneBookMenu.h"

// Structure created for Linked list
struct Contact
{
    char *name;
    char *phone_no;
    struct Contact *next;
};

// Function definition of Menu( which contains evrything on phonebook(like main.c for phonebook))
void PhoneBookMenu()
{
    while (1)
    {
        int choose;
        printf("MENU:\n\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contacts\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Choose the option: ");
        scanf("%d",&choose);

        switch (choose)
        {
            case 1:
            // Add_Contact();
                break;
            case 2:
                //Delete_Contact();
                break;
            case 3:
            // Search_Contact();
                break;
            case 4:
                //Display_Contact();
                break;
            default:
                printf("Exiting...\n");// deliberate choice (Exiting on any number than 1 to 4)
                return;
        }
    }
}