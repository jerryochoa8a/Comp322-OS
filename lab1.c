/*-----------------------------------------
LAB1:  Process Creation Hierarchy
-------------------------------------------
-To simulate process creation and destruction when 
implemented with linked lists.
==========================================  */
#include <stdio.h>
#include <stdlib.h>

/* Define structures and global constants, including:
the pcb type, the children linked list type, the maximum number of processes*/
struct PCB
{
   //1) parent: a PCB index corresponding to the process’ creator

   //2) children: a pointer to a linked list, where each node contains the PCB 
//    index of one child process and a link to the next child in the linked list
    
};

struct child
{
    int data;
    struct child *link;
};


/***************************************************************/
void Print_Hierarchy()
{ //"PROCEDURE TO PRINT HIERARCHY OF PROCESSES"
    /* declare local vars */
    /* for each process index i from 0 up to (but not including) maximum number
    of processes*/
    /* if PCB[i] is not NULL */
    /* print process id, parent id, list of children processes */
} /* end of procedure */


/***************************************************************/
void option1()
{ // "PROCEDURE FOR OPTION #1"
    /* declare local vars */
    /* Allocate memory for PCB[0] */
    /* Intitialize all other PCB's to NULL */
    /* print hierarchy of processes */
    return;
} /* end of procedure */


/***************************************************************/
void option2()
{ // "PROCDURE FOR OPTION #2"
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
    return;
} /* end of procedure */


/***************************************************************/
void distroyChildNode(struct Node* parameter)
{ //"RECURSIVE PROCEDURE TO DESTROY CHILDREN PROCESSES"
    /* declare local vars */
    /* check if end of linked list--if so return */
    /* else call self on next node in linked list */
    /* set variable q to current node's process index field */
    /* call self on children of PCB[q] */
    /* free memory of PCB[q] and set PCB[q] to NULL*/
    /* free memory of paramter and set to NULL */
    return;
} /* end of procedure */


/***************************************************************/
void option3()
{ //"PROCEDURE FOR OPTION #3"
    /* declare local vars */
    /* prompt for process index p */
    /* call recursive procedure to destroy children of PCB[p] */
    /* reset children of PCB[p] to NULL */
    /* print hierarchy of processes */
    return;
} /* end of procedure */


/***************************************************************/
void option4()
{ // "PROCEDURE FOR OPTION #4"
    /* if PCB[0] is non null)
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
    bool userExit=false;

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
            break;

        case 2:
            // Create a new child process
            break;

        case 3:
            // Destroy all descendants of a process
            break;

        case 4:
            // Quit program and free memory
            userExit = true;
            break;

        default:
            printf("Pick a listed option");
            break;
        }
    }

    return 1; /* indicates success */
} /* end of procedure */
