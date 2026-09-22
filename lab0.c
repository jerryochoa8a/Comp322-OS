#include<stdio.h>
#include<stdlib.h>

struct Person
{
    char name[50];
    char address[100];
    int phone;
};

struct Address_book
{
    struct Person *persons; // pointer for person structure
    int book_size;
};


struct Address_book* create_address_book()
{
    // Ask user for number of people to add
    int bookSize;
    printf("How many people are you adding to book: ");
    scanf("%d", &bookSize);

    // Empty Book Array: [Address_book]
    struct Address_book *AddrBookArr = malloc(sizeof(struct Address_book));

    // Store the number of people
    AddrBookArr->book_size = bookSize;
    
    // Person array in book: [Person][Person][Person]...
    struct Person *personArr = malloc(bookSize * sizeof(struct Person));
    AddrBookArr->persons = personArr;
    
    // loop to ask for each person info
    for (size_t i = 0; i < bookSize; i++)
    {
        printf("\nPerson #%d\n", i + 1);

        printf("Enter Name: ");
        scanf("%49s", AddrBookArr->persons[i].name);

        printf("Enter Address: ");
        scanf("%99s", AddrBookArr->persons[i].address);

        printf("Enter Phone: ");
        scanf("%d", &AddrBookArr->persons[i].phone);
    }
    
    // - Return the address book
    return AddrBookArr;
}


void print_person(struct Person* person)
{
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
    printf("Phone: %d\n", person->phone);

    printf("\n");
}


void print_address_book(struct Address_book *address_book)
{
    // loop through all the people in the book
    printf("\n");
    printf("======== ADDRESS BOOK ========");
    for (int i = 0; i < address_book->book_size; i++)
    {
        printf("\nPerson #%d\n", i + 1);
        // print one person from addr book.
        print_person(&address_book->persons[i]);
    }
    printf("\n");
}


void destroy_address_book(struct Address_book *address_book)
{
    //free the memory to prevent memory leaks
    free(address_book->persons);
    free(address_book);  
}


int main()
{    
    // Makes an address book 
    struct Address_book *book = create_address_book();

    // print Book
    print_address_book(book);

    // Free Memory
    destroy_address_book(book);    
    
    // Read from the standard input the number of persons that the 
    //user intends to put into the address book.
    
    // Dynamically allocate an array of struct Person of the correct size
    // and store a pointer to it in the address book.
    
    // In a loop, read from the standard input the information you need for 
    // every person to be stored in the address book. 
    // Assume that the inputs are correct, so you are not expected to validate them.
    
    // Return the address book.
}