#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype_Phonebook_Menu.h"
#include "config.h"


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
sContact *Node_First = NULL;


static void removeNewline(char *str);
static void Phonebook_Add(void);
static void Phonebook_Delete(void);
static void Phonebook_Search(void);
static void Phonebook_Display(void);
//void displayNode(void);



// Function definition of Menu( which contains evrything on phonebook(like main.c for phonebook))
void Phonebook_Menu()
{
#if DEBUG2
    printf("Phonebook_Menu() - Entry");
#endif
    while (1)
    {
        uint8 choose;
        printf("\n\nMENU:\n\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contacts\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("\nChoose the option: ");
        scanf("%d",&choose);
        getchar();
        printf("\n");

        switch (choose)
        {
            case 1:
                Phonebook_Add();
                break;
            case 2:
                Phonebook_Delete();
                break;
            case 3:
                Phonebook_Search();
                break;
            case 4:
                Phonebook_Display();
                break;
            default:
                printf("Exiting...\n");// deliberate choice (Exiting on any number than 1 to 4)
#if DEBUG2
    printf("Phonebook_Menu() - Exit");
#endif
                return;
        }       
    }

}
static void removeNewline(char *str)
{
    str[strcspn(str,"\n")] = '\0';
}

static void Phonebook_Add(void)
{
#if DEBUG2
    printf("Phonebook_Add() - Entry\n");
#endif
    printf("ADD CONTACT:\n\n");
    int8 nm[50],ph_no[20];
    sContact *p=Node_First,*old;

    //Taking user Input:
    printf("Enter Name:\n");
    fgets(nm,50,stdin);
    removeNewline(nm);
    printf("Enter Phone No:\n");
    scanf("%s",&ph_no);//check
    // Dynamically Allocating memory for newNode
    sContact *newNode = (sContact*) malloc(sizeof(sContact));
#if DEBUG1
    printf("newNode - %d\n",newNode);
#endif
    if (NULL == newNode)
    {
        printf("Memory not Allocated\n");
#if DEBUG1
    printf("newNode - %d\n",newNode);
#endif
        return;
    }
    // copying the name and phone no to the newNode
    strcpy(newNode->name, nm);
    strcpy(newNode->phone_no,ph_no);
    //Set newNode next to NULL
    newNode -> next = NULL;
    // if List is Empty
    if (NULL == Node_First)
    {
        Node_First = newNode;
        printf("Contact Added Successfully\n");
#if DEBUG2
    printf("Phonebook_Add() - Exit\n");
#endif
        return;
    }
    //if list is not empty, do string comparision,to check whether new Node comes before Node_First
    if (strcmp(newNode -> name, Node_First -> name) < 0)
    {
        newNode ->next = Node_First;
        Node_First = newNode;
        printf("Contact Added Successfully\n");
#if DEBUG2
    printf("Phonebook_Add() - Exit\n");
#endif 
        return;
    }
    // if Node_First is less alphatical order than newNode
    while(NULL != p && strcmp(newNode -> name,p->name)>0)
    {
        old = p;
        p = p -> next;
    }
    old->next = newNode;
    newNode -> next = p;
#if DEBUG2
    printf("Phonebook_Add() - Exit\n");
#endif    
    return;
}


/*
// this function is for testing
void displayNode(void)
{
    sContact *temp = Node_First;
    unsigned char i = 1;
    while(temp != NULL)
    {   
       printf("%s\t\t",temp-> name);
       printf("%s\n",temp->phone_no);
       temp = temp->next;
    }
}
*/

static void Phonebook_Delete(void)
{
#if DEBUG2
    printf("Phonebook_Delete() - Entry\n");
#endif 
    printf("DELETE CONTACT:\n\n");
    int8 nm[50];
    printf("Enter Name:\n");
    fgets(nm, 50, stdin);
    removeNewline(nm);

    sContact *p = Node_First;
    sContact *temp;

    // If list is empty
    if (p == NULL)
    {
        printf("No Contact to delete\n");
#if DEBUG2
    printf("Phonebook_Delete() - Exit\n");
#endif 
        return;
    }

    // If name matches Node_First node
    if (strcmp(p->name, nm) == 0)
    {
        Node_First = p->next;
        free(p);
        printf("Contact Deleted Successfully\n");
#if DEBUG2
    printf("Phonebook_Delete() - Exit\n");
#endif 
        return;
    }

    // Traverse and find matching node in p->next
    while (p->next != NULL)
    {
        if (strcmp(p->next->name, nm) == 0)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
            printf("Contact Deleted Successfully\n");
#if DEBUG2
    printf("Phonebook_Delete() - Exit\n");
#endif    
            return;
        }
        p = p->next;
    }

    printf("No Match Contact Found\n");
#if DEBUG2
    printf("Phonebook_Delete() - Exit\n");
#endif 
    return;
}

static void Phonebook_Search(void)
{
#if DEBUG2
    printf("Phonebook_Search() - Entry\n");
#endif 
    int8 nm[50];
    int32 len,index=1;
    sContact *p = Node_First;
    printf("Enter Name:\n");
    fgets(nm, 50, stdin);
    removeNewline(nm);
    len = strlen(nm);
    // Check if List is Empty or Not
    // If it is Empty
    if (NULL == Node_First)
    {
        printf("No contacts to search");
#if DEBUG2
    printf("Phonebook_Search() - Exit\n");
#endif
        return;
    }
    // If list is Not Empty
    printf("\n%-5s %-30s %-20s\n", "S.No", "Name", "Phone Number");
    printf("------------------------------------------------------------\n");
    while ( NULL != p)
    {
        if (strncmp(p->name,nm,len) == 0)
        {
            printf("%-5d %-30s %-20s\n", index, p->name, p->phone_no);
            index++;
        }
        p = p -> next;
    }
    if (index > 1)
    {
        printf("Search Result Found\n");
    }
    else
    {
        printf("Search Result Not Found\n");
    }
#if DEBUG2
    printf("Phonebook_Search() - Exit\n");
#endif
    return;

    
}

static void Phonebook_Display(void)
{
#if DEBUG2
    printf("Phonebook_Display() - Entry\n");
#endif 
    sContact *temp = Node_First;
    uint8 index = 1;

    if (temp == NULL)
    {
        printf("Phonebook is empty.\n");
#if DEBUG2
    printf("Phonebook_Display() - Exit\n");
#endif 
        return;
    }

    printf("\n%-5s %-30s %-20s\n", "S.No", "Name", "Phone Number");
    printf("------------------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-5d %-30s %-20s\n", index, temp->name, temp->phone_no);
        temp = temp->next;
        index++;
    }

#if DEBUG2
    printf("Phonebook_Display() - Exit\n");
#endif 
    return;
}
