#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int front, rear, count, maxsize;
    void** arr;
} Queue;

// Function Prototypes
Queue* create_queue(int size);
bool enqueue(Queue* qp, void* data);
void* dequeue(Queue* qp);
void* queue_front(Queue* qp);
void* queue_rear(Queue* qp);
int queue_count(Queue* qp);
bool queue_empty(Queue* qp);
bool queue_full(Queue* qp);
Queue* destroy_queue(Queue* qp);
void display_queue(Queue* qp, void (*display_func)(void*));
void display_data(void* data);

// Function Definitions
Queue* create_queue(int size) {
    Queue* qp = (Queue*)malloc(sizeof(Queue));
    if (!qp) return NULL;

    qp->front = 0;
    qp->rear = -1;
    qp->count = 0;
    qp->maxsize = size;
    qp->arr = (void**)calloc(size, sizeof(void*));
    if (!qp->arr) {
        free(qp);
        return NULL;
    }
    return qp;
}

bool enqueue(Queue* qp, void* data) {
    if (queue_full(qp)) return false;  // Queue is full

    qp->rear++;
    qp->arr[qp->rear] = data;
    qp->count++;
    return true;
}

void* dequeue(Queue* qp) {
    if (queue_empty(qp)) return NULL;  // Queue is empty

    void* data = qp->arr[qp->front];
    qp->arr[qp->front] = NULL;  // Clear the slot (optional)
    qp->front++;
    qp->count--;
    return data;
}

void* queue_front(Queue* qp) {
    return queue_empty(qp) ? NULL : qp->arr[qp->front];
}

void* queue_rear(Queue* qp) {
    return queue_empty(qp) ? NULL : qp->arr[qp->rear];
}

int queue_count(Queue* qp) {
    return qp->count;
}

bool queue_empty(Queue* qp) {
    return qp->count == 0;
}

bool queue_full(Queue* qp) {
    return qp->count == qp->maxsize;
}

Queue* destroy_queue(Queue* qp) {
    if (qp) {
        for (int i = qp->front; i <= qp->rear; i++) {
            free(qp->arr[i]);  // Free stored data (optional)
        }
        free(qp->arr);
        free(qp);
    }
    return NULL;
}

void display_queue(Queue* qp, void (*display_func)(void*)) {
    if (queue_empty(qp)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents:\n");
    for (int i = qp->front; i <= qp->rear; i++) {
        display_func(qp->arr[i]);
    }
}

void display_data(void* data) {
    printf("Data: %s\n", (char*)data);  // Example for string data
}

// Main function demonstrating usage
int main() {
    int choice, size;
    char* data;
    Queue* my_queue;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    my_queue = create_queue(size);

    printf("Linear Queue Application\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display front element\n");
        printf("4. Display rear element\n");
        printf("5. Display all elements\n");
        printf("6. Check if queue is empty\n");
        printf("7. Check total number of elements\n");
        printf("8. Destroy queue and exit\n");
        printf("9. Check if queue is full\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (queue_full(my_queue)) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    data = (char*)malloc(100 * sizeof(char));
                    printf("Enter data: ");
                    scanf(" %[^\n]", data);
                    if (enqueue(my_queue, data)) {
                        printf("Data enqueued successfully!\n");
                    } else {
                        printf("Failed to enqueue data.\n");
                        free(data);
                    }
                }
                break;

            case 2:
                data = (char*)dequeue(my_queue);
                if (data) {
                    printf("Dequeued data: %s\n", data);
                    free(data);
                } else {
                    printf("Queue is empty. Nothing to dequeue.\n");
                }
                break;

            case 3:
                data = (char*)queue_front(my_queue);
                if (data) {
                    printf("Front element: %s\n", data);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            case 4:
                data = (char*)queue_rear(my_queue);
                if (data) {
                    printf("Rear element: %s\n", data);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            case 5:
                display_queue(my_queue, display_data);
                break;

            case 6:
                printf(queue_empty(my_queue) ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;

            case 7:
                printf("Total elements in queue: %d\n", queue_count(my_queue));
                break;

            case 8:
                my_queue = destroy_queue(my_queue);
                printf("Queue destroyed. Exiting...\n");
                return 0;

            case 9:
                printf(queue_full(my_queue) ? "Queue is full.\n" : "Queue is not full.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
