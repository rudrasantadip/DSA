// C program to create a Queue with a stack

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int* array;
    int top;
    unsigned capacity;
};

// Function to create a stack with an initial capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        exit(1);
    }
    stack->array[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        exit(1);
    }
    return stack->array[stack->top--];
}

// Structure to represent a queue using two stacks
struct Queue {
    struct Stack* stack1; // For enqueue operation
    struct Stack* stack2; // For dequeue operation
};

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, int data) {
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
    push(queue->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    while (!isEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    if (isEmpty(queue->stack2)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    return pop(queue->stack2);
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
    if (isEmpty(queue->stack1)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= queue->stack1->top; i++) {
        printf("%d ", queue->stack1->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);

    int dequeued = dequeue(queue);
    printf("Dequeued: %d\n", dequeued);

    display(queue);

    enqueue(queue, 40);
    enqueue(queue, 50);

    display(queue);

    return 0;
}
