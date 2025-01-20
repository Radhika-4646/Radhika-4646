#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void *data;
    struct node *next;
} NODE;
typedef struct queue {
    int count;
    NODE *front;
    NODE *rear;
} QUEUE;
QUEUE* create_queue();
bool enqueue(QUEUE *, void *data);
void* dequeue(QUEUE *);
void* queue_front(QUEUE *);
void* queue_rear(QUEUE *);
int queue_count(QUEUE *);
bool queue_empty(QUEUE *);
bool queue_full(QUEUE *qp);
bool destroy_queue(QUEUE *);
void display_queue(QUEUE *, void (*display_func)(void *));

QUEUE* create_queue() {
    QUEUE *qp = (QUEUE *)malloc(sizeof(QUEUE));
    if (qp) {
        qp->count = 0;
        qp->front = NULL;
        qp->rear = NULL;
    }
    return qp;
}
bool enqueue(QUEUE *qp, void *data) {
    // Step 1: Create a new node
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (!temp) return false;  // Memory allocation failed

    temp->data = data;
    temp->next = NULL;

    // Step 2: Check if the queue is empty
    if (qp->rear == NULL) {
        qp->front = temp;    // Both front and rear point to the new node
        qp->rear = temp;
    } else {
        // Step 3: Link new node to the rear and update rear pointer
        qp->rear->next = temp;
        qp->rear = temp;
    }

    // Step 4: Increment the queue count
    qp->count++;
    return true;  // Enqueue successful
}

void* dequeue(QUEUE *qp) {
     NODE *temp ;
     void *data_out ;
    if (qp->front == NULL) {
        return NULL;
    }
    temp = qp->front;
    qp->front = temp->next;
    if (qp->front == NULL) {
        qp->rear = NULL;  // If queue becomes empty, set rear to NULL
    }

    +data_out = temp->data;
    free(temp);
    qp->count--;
    return data_out;
}

void* dequeue(QUEUE *qp)
{
    NODE *temp
    void *data_out
    if (!qp->count) return NULL;

    temp = qp->front;
    data_out = temp->data;
    qp->front = temp->next;

    if (!qp->front) {
        qp->rear = NULL;
    }
    free(temp);
    qp->count--;
    return data_out;
}

void* queue_front(QUEUE *qp) {
    return qp->front ? qp->front->data : NULL;
}

void* queue_rear(QUEUE *qp) {
    return qp->rear ? qp->rear->data : NULL;
}

int queue_count(QUEUE *qp) {
    return qp->count;
}

bool queue_empty(QUEUE *qp) {
    return qp->count == 0;
}

bool queue_full(QUEUE *qp) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (!temp) return true;

    free(temp);
    return false;
}

bool destroy_queue(QUEUE *qp) {
    if (!qp) return false;

    NODE *temp;
    while (qp->front) {
        temp = qp->front;
        qp->front = temp->next;
        free(temp->data);
        free(temp);
    }
    free(qp);
    return true;
}

void display_queue(QUEUE *qp, void (*display_func)(void *)) {
    NODE *temp = qp->front;
    while (temp) {
        display_func(temp->data);
        temp = temp->next;
    }
}

