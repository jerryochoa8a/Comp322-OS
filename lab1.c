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

    /* for each process index i from 0 up to (but not including) maximum number
    of processes*/
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
                printf("\tParent process: %d\n", pcb[i]->children);
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
    /* define local vars */

    /* prompt for parent process index p */
    
    /* if PCB[p] is NULL, print message process does not exist, return */
    
    /* search for first available index q without a parent in a while loop */
    
    /* if maximum number of processes reached, print message of no more avaiable
    PCBs */
    
    /* allocate memory for new child process, initialize fields */
    
    /* record the parent's index p in PCB[q] */
    
    /* initialize the list of children of PCB[q] as empty */
    
    /* append the node containing the child's index q to the children linked list
    of PCB[p] */
    
    /* print hierarchy of processes */
    Print_Hierarchy();
    return;
} /* end of procedure */

/***************************************************************/

// void distroyChildNode(struct Node* parameter)
// { //"RECURSIVE PROCEDURE TO DESTROY CHILDREN PROCESSES"
//     /* declare local vars */
//     /* check if end of linked list--if so return */
//     /* else call self on next node in linked list */
//     /* set variable q to current node's process index field */
//     /* call self on children of PCB[q] */
//     /* free memory of PCB[q] and set PCB[q] to NULL*/
//     /* free memory of paramter and set to NULL */
//     return;
// } /* end of procedure */

/***************************************************************/

void option3()
{ //"PROCEDURE#3 - Destroy all descendants of a process
    /* declare local vars */
    /* prompt for process index p */
    /* call recursive procedure to destroy children of PCB[p] */
    /* reset children of PCB[p] to NULL */
    /* print hierarchy of processes */
    return;
} /* end of procedure */

/***************************************************************/

void option4()
{ // "PROCEDURE#4 - Quit program and free memory
    /* if PCB[0] is non null) */
    /* if children of PCB[0] is not null */
    /* call recursive procedure to destroy children of PCB[0] */
    /* free memory of all PCB's */
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
        printf("\n");

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
