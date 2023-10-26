// Write a program to insert a value at any vacant position at the rear of a queue

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
struct Queue {
    int* array;
    int front, rear;
    unsigned capacity;
};

// Function to create a queue with an initial capacity
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to enqueue an element at any vacant position at the rear
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        // If the queue is full, dynamically resize it
        queue->capacity *= 2;
        queue->array = (int*)realloc(queue->array, queue->capacity * sizeof(int));
        if (!queue->array) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }

    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->array[queue->rear] = data;
    printf("%d enqueued into the queue.\n", data);
}

// Function to dequeue an element from the front
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }

    return data;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60); // Causes dynamic resizing

    display(queue);

    int dequeued = dequeue(queue);
    printf("Dequeued: %d\n", dequeued);

    display(queue);

    return 0;
}
