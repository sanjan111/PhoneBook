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

static void removeNewline(char *str);
static void Phonebook_Add(void);
static void Phonebook_Delete(void);
void displayNode(void);



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
                printf("\n\nDisplaying\n");
                displayNode();
                printf("\n");
                break;
            case 2:
                Phonebook_Delete();
                printf("\n\nDisplaying\n");
                displayNode();
                printf("\n");
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
static void removeNewline(char *str)
{
    str[strcspn(str,"\n")] = '\0';
}

static void Phonebook_Add(void)
{
    printf("ADD CONTACT:\n");
    int8 nm[50],ph_no[20];
    sContact *p=first,*old;
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
    // if first is less alphatical order than newNode
    while(NULL != p && strcmp(newNode -> name,p->name)>0)
    {
        old = p;
        p = p -> next;
    }
    old->next = newNode;
    newNode -> next = p;
     
}



void displayNode(void)
{
    sContact *temp = first;
    unsigned char i = 1;
    while(temp != NULL)
    {   
       printf("%s\t\t",temp-> name);
       printf("%s\n",temp->phone_no);
       temp = temp->next;
    }
}

static void Phonebook_Delete(void)
{
    printf("DELETE CONTACT:\n");
    int8 nm[50];
    int32 count = 0;
    sContact *p=first,*old=NULL;
    //Taking user Input:
    printf("Enter Name:\n");
    fgets(nm,50,stdin);
    removeNewline(nm);

    // if List is Empty
    if (NULL == first)
    {
        printf("No Contact to delete\n");
        return;
    }
    // if value found in first node
    if (first -> name == nm)
    {
        first = first -> next;
        free(p);// remeber earlier p = first
        printf("Contacted Deleted Successfully\n");
        return; 
    }
    // if name is  not found in first 
    while (NULL != p -> next)
    {
        old = p;
        p =  p->next;
        if (old->name == nm)
        {
            old -> next = p->next;
            free(p);
            printf("Contacted Deleted Successfully\n");
            return;
        }
         
    }
    if (p->next ->name ==nm)
    {
        old -> next = NULL;
        free(p->next);
        printf("Contacted Deleted Successfully\n");
    }
    else
    {
        printf("No Match Contact Found\n");
    }
}