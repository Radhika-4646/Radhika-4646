#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int count, maxsize, top;
    void** starr;
} stack;
stack* create_stack(int size);
bool push_stack(stack* sp, void* pdata);
void* pop_stack(stack* sp);
void* stack_top(stack* sp);
int stack_count(stack* sp);
bool stack_empty(stack* sp);
bool stack_full(stack* sp);
stack* destroy_stack(stack* sp);
void display_stack(stack* sp, void (*display_func)(void*));
void display_data(void* data);
stack* create_stack(int size) {
    stack* sp = (stack*)malloc(sizeof(stack));
    if (!sp) {
        return NULL;
    } else {
        sp->count = 0;
        sp->maxsize = size;
        sp->top = -1;
        sp->starr = (void**)calloc(size, sizeof(void*));
        if (!(sp->starr)) {
            free(sp);
            return NULL;
        }
        return sp;
    }
}
bool push_stack(stack* sp, void* pdata) {
    if (sp->count == sp->maxsize) {
        return false;  // Stack is full
    }
    (sp->top)++;
    sp->starr[sp->top] = pdata;
    (sp->count)++;
    return true;  // Successfully pushed
}

// 3. Pop a data item from the stack
void* pop_stack(stack* sp) {
    void* dptr;
    if (sp->count == 0) {
        return NULL;  // Stack is empty
    } else {
        dptr = sp->starr[sp->top];
        (sp->top)--;
        (sp->count)--;
        return dptr;
    }
}

// 4. View the data item on top of the stack
void* stack_top(stack* sp) {
    if (sp->count == 0) {
        return NULL;  // Stack is empty
    } else {
        return sp->starr[sp->top];  // Return the item at the top
    }
}

// 5. Get the number of items in the stack
int stack_count(stack* sp) {
    return sp->count;
}

// 6. Check if the stack is empty
bool stack_empty(stack* sp) {
    return (sp->count == 0);
}

// 7. Check if the stack is full
bool stack_full(stack* sp) {
    return (sp->count == sp->maxsize);
}

// 8. Destroy the stack and free the memory
stack* destroy_stack(stack* sp) {
    if (sp) {
        for (int i = sp->top; i >= 0; i--) {
            free(sp->starr[i]);
        }
        free(sp->starr);
        free(sp);
    }
    return NULL;
}

// 9. Display the stack using a custom display function
void display_stack(stack* sp, void (*display_func)(void*)) {
    for (int i = sp->top; i >= 0; i--) {
        display_func(sp->starr[i]);
    }
}

// Function to display the details of a data item
void display_data(void* data) {
    // For example, assuming this is for movies, you can display movie details here
    printf("Data Item: %s\n", (char*)data);  // Replace this with actual data structure
}

// Main function demonstrating how to use the stack
int main() {
    stack* my_stack = create_stack(5);
    int choice;
    char* movie_name;

    printf("Stack Application\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push a movie\n");
        printf("2. Pop a movie\n");
        printf("3. View top movie\n");
        printf("4. Display all movies\n");
        printf("5. Check if stack is empty\n");
        printf("6. Check total number of movies\n");
        printf("7. Destroy stack and exit\n");
        printf("8. Check if stack is full\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (stack_full(my_stack)) {
                    printf("Stack is full. Cannot push a new movie.\n");
                    break;
                }
                movie_name = (char*)malloc(100 * sizeof(char));
                if (movie_name) {
                    printf("Enter movie name: ");
                    scanf(" %[^\n]", movie_name);
                    if (push_stack(my_stack, movie_name)) {
                        printf("Movie pushed successfully!\n");
                    } else {
                        printf("Failed to push movie!\n");
                        free(movie_name);
                    }
                }
                break;

            case 2:
                movie_name = (char*)pop_stack(my_stack);
                if (movie_name) {
                    printf("Popped movie: %s\n", movie_name);
                    free(movie_name);
                } else {
                    printf("Stack is empty, nothing to pop!\n");
                }
                break;

            case 3:
                movie_name = (char*)stack_top(my_stack);
                if (movie_name) {
                    printf("Top movie: %s\n", movie_name);
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 4:
                printf("Movies in stack:\n");
                display_stack(my_stack, display_data);
                break;

            case 5:
                if (stack_empty(my_stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 6:
                printf("Total movies in stack: %d\n", stack_count(my_stack));
                break;

            case 7:
                my_stack = destroy_stack(my_stack);
                printf("Stack destroyed and exited.\n");
                return 0;

            case 8:
                if (stack_full(my_stack)) {
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
