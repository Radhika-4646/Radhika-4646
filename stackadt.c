#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the NODE structure
typedef struct node {
    void *data;
    struct node *next;
} NODE;

// Define the STACK structure
typedef struct stack {
    int count;
    NODE *top;
} STACK;

// Stack ADT function prototypes
STACK* create_stack();
bool push_stack(STACK *, void *din);
void* pop_stack(STACK *);
void* stack_top(STACK *);
int stack_count(STACK *);
bool stack_empty(STACK *);
int stack_full(STACK *sp) ;
bool destroy_stack(STACK *);
void display_stack(STACK *, void (*display_func)(void *));

// Stack ADT function implementations
STACK* create_stack() {
    STACK *sp = (STACK *)malloc(sizeof(STACK));
    if (sp) {
        sp->count = 0;
        sp->top = NULL;
    }
    return sp;
}

bool push_stack(STACK *sp, void *din) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (!temp) return false;

    temp->data = din;
    temp->next = sp->top;
    sp->top = temp;
    sp->count++;
    return true;
}

void* pop_stack(STACK *sp) {
    if (!sp->count) return NULL;

    NODE *temp = sp->top;
    void *data_out = temp->data;
    sp->top = temp->next;
    free(temp);
    sp->count--;
    return data_out;
}

void* stack_top(STACK *sp) {
    return sp->count ? sp->top->data : NULL;
}

int stack_count(STACK *sp) {
    return sp->count;
}

bool stack_empty(STACK *sp) {
    return sp->count == 0;
}
int stack_full(STACK *sp) {
node* temp;
temp=(node*)malloc(sizeof(node));
if(!temp)
return 1;
else
free(temp);
return 0;

}

bool destroy_stack(STACK *sp) {
    if (!sp) return false;

    NODE *temp;
    while (sp->top) {
        temp = sp->top;
        sp->top = temp->next;
        free(temp->data);
        free(temp);
    }
    free(sp);
    return true;
}

void display_stack(STACK *sp, void (*display_func)(void *)) {
    NODE *temp = sp->top;
    while (temp) {
        display_func(temp->data);
        temp = temp->next;
    }
}

// Application: Stack of Books
typedef struct book {
    char title[50];
    char author[50];
    int year;
} BOOK;

// Function to display a book
void display_book(void *data) {
    BOOK *b = (BOOK *)data;
    if (b) {
        printf("Title: %s\n", b->title);
        printf("Author: %s\n", b->author);
        printf("Year: %d\n\n", b->year);
    }
}

int main() {
    STACK *book_stack = create_stack();
    int choice;
    BOOK *b;

    printf("Stack Application: Books\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push a book\n");
        printf("2. Pop a book\n");
        printf("3. View top book\n");
        printf("4. Display all books\n");
        printf("5. Check if stack is empty\n");
        printf("6. Check total number of books\n");
        printf("7. Destroy stack and exit\n");
        printf("8. stack and full\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                b = (BOOK *)malloc(sizeof(BOOK));
                if (b) {
                    printf("Enter book title: ");
                    scanf(" %[^\n]", b->title);
                    printf("Enter author name: ");
                    scanf(" %[^\n]", b->author);
                    printf("Enter publication year: ");
                    scanf("%d", &b->year);

                    if (push_stack(book_stack, b)) {
                        printf("Book pushed successfully!\n");
                    } else {
                        printf("Failed to push book!\n");
                        free(b);
                    }
                }
                break;

            case 2:
                b = (BOOK *)pop_stack(book_stack);
                if (b) {
                    printf("Popped book details:\n");
                    display_book(b);
                    free(b); // Free the memory of the popped book
                } else {
                    printf("Stack is empty, nothing to pop!\n");
                }
                break;

            case 3:
                b = (BOOK *)stack_top(book_stack);
                if (b) {
                    printf("Top book details:\n");
                    display_book(b);
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 4:
                printf("Books in stack:\n");
                display_stack(book_stack, display_book);
                break;

            case 5:
                if (stack_empty(book_stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 6:
                printf("Total books in stack: %d\n", stack_count(book_stack));
                break;

            case 7:
                if (destroy_stack(book_stack)) {
                    printf("Stack destroyed successfully. Exiting...\n");
                } else {
                    printf("Failed to destroy stack.\n");
                }
                return 0;
            case 8:
                if (stack_full(book_stack)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
