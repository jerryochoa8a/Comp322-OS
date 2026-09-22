#include <stdio.h>
#include <stdlib.h>

/* Person structure */
typedef struct {
    char name[100];
    char address[200];
    char phone[20];
} Person;

/* Address book structure */
typedef struct {
    Person* persons;
    int number_of_persons;
} Address_book;

/* Function declarations */
void print_address_book(const Address_book* address_book);
Address_book* create_address_book(void);
void destroy_address_book(Address_book* address_book);


/* Prints everyone in the address book */
void print_address_book(const Address_book* address_book)
{
    for (int i = 0; i < address_book->number_of_persons; i++)
    {
    printf("\nPerson %d:\n", i + 1);
    printf("Name: %s\n", &address_book->persons->name);
    printf("Address: %s\n", &address_book->persons->address);
    printf("Phone: %s\n", &address_book->persons->phone);
    }
}

/* Creates the address book */
Address_book* create_address_book(void)
{
    /* Dynamically create the address book */
    Address_book* address_book =
    malloc(sizeof(Address_book));


    /* Ask how many people */
    printf("How many people do you want to add? ");
    scanf("%d", &address_book->number_of_persons);

    /* Dynamically allocate the array of people */
    address_book->persons =
        malloc(sizeof(Person) *
            address_book->number_of_persons);

    /* Get information for each person */
    for (int i = 0;
        i < address_book->number_of_persons;
        i++)
    {
        printf("\nPerson %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %99[^\n]",
            address_book->persons[i].name);

        printf("Enter address: ");
        scanf(" %199[^\n]",
            address_book->persons[i].address);

        printf("Enter phone number: ");
        scanf(" %19s",
            address_book->persons[i].phone);
}

return address_book;


}

/* Frees all dynamically allocated memory */
void destroy_address_book(Address_book* address_book)
{
    free(address_book->persons);
    free(address_book);
}

/* Main function for testing */
int main(void)
{
    Address_book* address_book =
    create_address_book();

    printf("\n--- ADDRESS BOOK ---\n");

    print_address_book(address_book);

    destroy_address_book(address_book);

    return 0;

}
