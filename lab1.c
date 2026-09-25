/*-----------------------------------------
LAB1:  Process Creation Hierarchy
-------------------------------------------
-To simulate process creation and destruction when
implemented with linked lists.
==========================================  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool

/* Define structures and global constants, including:
the pcb type, the children linked list type, the maximum number of processes*/

typedef struct childNode
{
    int index;
    struct childNode *link;
} childNode;

typedef struct PCB
{
    int parent;
    childNode *children;
} PCB;

#define MAX_PROCESSES 5

PCB *pcb[MAX_PROCESSES] = {NULL};

/***************************************************************/
void Print_Hierarchy()
{ //"PROCEDURE TO PRINT HIERARCHY OF PROCESSES"
    /* declare local vars */
    childNode *current;

    /* for each process index i from 0 up to (but not including) maximum number
    of processes*/
    printf("\nProcess list:\n");
    for (int i = 0; i < MAX_PROCESSES; i++)
    {

        /* if PCB[i] is not NULL */
        if (pcb[i] != NULL)
        {

            /* print process id, parent id, list of children processes */
            printf("Process id: %d\n", i);
            if (pcb[i]->parent == -1)
            {
                printf("\tNo Parent processes\n");
            }
            else
            {
                printf("\tParent process: %d\n", pcb[i]->parent);
            }

            if (pcb[i]->children == NULL)
            {
                printf("\tNo child processes\n");
            }
            else
            {
                current = pcb[i]->children;

                while (current != NULL)
                {
                    printf("\tChild process: %d\n", current->index);
                    current = current->link;
                }
            }
        }
    }

} /* end of procedure */

/***************************************************************/
void option1()
{ // Initialize process hierarchy
    /* declare local vars */

    /* Allocate memory for PCB[0] */
    pcb[0] = malloc(sizeof(PCB));
    pcb[0]->parent = -1;
    pcb[0]->children = NULL;

    /* Intitialize all other PCB's to NULL */
    for (int i = 1; i < MAX_PROCESSES; i++)
    {
        pcb[i] = NULL;
    }

    /* print hierarchy of processes */
    Print_Hierarchy();

    return;
} /* end of procedure */

/***************************************************************/

void option2()
{ // "PROCDURE#2 - Create a new child process

    // allocate memory for an unused PCB[q]
    //  record the parent's index, p, in PCB[q]
    //  initialize the list of children of PCB[q] as empty (NULL)
    //  create a new link containing the child's index q and append the link to the
    // children field of PCB[p]

    /* define local vars */
    int p;
    int q = 0;
    childNode *newNode;
    childNode *current;

    /* prompt for parent process index p */
    printf("Enter the parent process id: ");
    scanf("%d", &p);

    /* if PCB[p] is NULL, print message process does not exist, return */
    if (pcb[p] == NULL)/**/
    {
        printf("\nprocess does not exit");
        return;
    }

    /* search for first available index q without a parent in a while loop */
    while (q < MAX_PROCESSES && pcb[q] != NULL)
    {
        q++;
    }

    /* if maximum number of processes reached, print message of no more avaiable
    PCBs */
    if (q == MAX_PROCESSES)
    {
        printf("\nNo more avaiable PCBs");
        return;
    }

    /* allocate memory for new child process, initialize fields */
    pcb[q] = malloc(sizeof(PCB)); // getting memmory for new pcb[q]

    /* record the parent's index p in PCB[q] */
    pcb[q]->parent = p;

    /* initialize the list of children of PCB[q] as empty */
    pcb[q]->children = NULL;

    /* append the node containing the child's index q to the children linked list
    of PCB[p] */
    newNode = malloc(sizeof(childNode));

    newNode->index = q;
    newNode->link = NULL;

    if (pcb[p]->children == NULL)
    {
        pcb[p]->children = newNode;
    }
    else
    {
        current = pcb[p]->children;

        while (current->link != NULL)
        {
            current = current->link;
        }

        current->link = newNode;
    }

    /* print hierarchy of processes */
    Print_Hierarchy();
    return;
} /* end of procedure */

/***************************************************************/

void distroyChildNode(childNode *parameter)
{ //"RECURSIVE PROCEDURE TO DESTROY CHILDREN PROCESSES"
    /* declare local vars */
    int q;

    /* check if end of linked list--if so return */
    if (parameter == NULL)
    {
        return;
    }
    else
    {

        /* else call self on next node in linked list */
        distroyChildNode(parameter->link);

        /* set variable q to current node's process index field */
        q = parameter->index;

        /* call self on children of PCB[q] */
        distroyChildNode(pcb[q]->children);

        /* free memory of PCB[q] and set PCB[q] to NULL*/
        free(pcb[q]);
        pcb[q] = NULL;

        /* free memory of paramter and set to NULL */
        free(parameter);
        parameter = NULL;
    }

    return;
} /* end of procedure */

/***************************************************************/

void option3()
{ //"PROCEDURE#3 - Destroy all descendants of a process
    /* declare local vars */
    int p;

    /* prompt for process index p */
    printf("Enter the parent process whose descendants are to be destroyed: ");
    scanf("%d", &p);

    /* call recursive procedure to destroy children of PCB[p] */
    distroyChildNode(pcb[p]->children);

    /* reset children of PCB[p] to NULL */
    pcb[p]->children = NULL;

    /* print hierarchy of processes */
    Print_Hierarchy();

    return;
} /* end of procedure */

/***************************************************************/

void option4()
{ // "PROCEDURE#4 - Quit program and free memory
    printf("Quitting program...\n");
    /* if PCB[0] is non null) */
    if (pcb[0] != NULL)
    {
        /* if children of PCB[0] is not null */
        if (pcb[0]->children != NULL)
        {
            /* call recursive procedure to destroy children of PCB[0] */
            distroyChildNode(pcb[0]->children);
            pcb[0]->children = NULL;
        }

        free(pcb[0]);
        pcb[0] = NULL;
    }

    /* free memory of all PCB's */
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        if (pcb[i] != NULL)
        {
            free(pcb[i]);
            pcb[i] = NULL;
        }
    }

    return;
} /* end of procedure */
/***************************************************************/

int main()
{
    /* declare local vars */
    int userInput;
    bool userExit = false;

    /* while user has not chosen to quit */
    while (!userExit)
    {
        /* print menu of options */
        printf("\nProcess creation and destruction\n");
        printf("--------------------------------\n");
        printf("1) Initialize process hierarchy\n");
        printf("2) Create a new child process\n");
        printf("3) Destroy all descendants of a process\n");
        printf("4) Quit program and free memory\n");
        printf("\n");

        /* prompt for menu selection */
        printf("Enter Selection: ");
        scanf("%d", &userInput);

        /* call appropriate procedure based on choice--use switch statement or
        series of if, else if, else statements */
        switch (userInput)
        {
        case 1:
            // Initialize process hierarchy
            option1();
            break;

        case 2:
            // Create a new child process
            option2();
            break;

        case 3:
            // Destroy all descendants of a process
            option3();
            break;

        case 4:
            // Quit program and free memory
            option4();
            userExit = true;
            break;

        default:
            printf("Pick a listed option");
            break;
        }
    }

    return 1; /* indicates success */
} /* end of procedure */
