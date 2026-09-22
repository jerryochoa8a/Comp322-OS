/* ===========  */
/* LAB1:  */
/* ===========  */
#include <stdio.h>
#include <stdlib.h>

/* EX of Self Referential Structure */
// struct abc
// {
//     int a;
//     char b;
//     struct abc *self
// };

struct node
{
    int data; // this could be any data type
    struct node *link; // Pointer to another node
};


int main(void)
{
    // Starting Pointer
    struct node *head = NULL;
    // allocate memory to make a node - points to created node
    head =  (struct node *)malloc(sizeof(struct node));
    // setting the heads data
    head->data = 11;
    head->link = NULL;

    struct node *current = NULL;
    current = malloc(sizeof(struct node));
    current->data = 22;
    current->link = NULL;
    // pointing the head to the current node
    head->link = current;

    struct node *current2 = NULL;
    current2 = malloc(sizeof(struct node));
    current2->data = 33;
    current2->link = NULL;
    // pointing the head to the current node
    current->link = current2;
    // or you could do: head->link-link = current


    printf("%d", head->data); // Print Head Node
    printf("\n");
    printf("%d", head->link->data); // Print Second Node
    printf("\n");
    printf("%d", head->link->link->data); // Print Third Node
    return 0;

}
