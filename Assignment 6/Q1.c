// Write a program to implement a dequeue with the help of linked list

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the deque
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Structure for the deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the deque
void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == NULL && deque->rear == NULL);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("%d inserted at the front of the deque.\n", data);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = createNode(data);

    if (isEmpty(deque)) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("%d inserted at the rear of the deque.\n", data);
}

// Function to remove an element from the front of the deque
int removeFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the front.\n");
        exit(1);
    }

    struct Node* temp = deque->front;
    int data = temp->data;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    free(temp);
    return data;
}

// Function to remove an element from the rear of the deque
int removeRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the rear.\n");
        exit(1);
    }

    struct Node* temp = deque->rear;
    int data = temp->data;

    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    free(temp);
    return data;
}

// Function to display the elements of the deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque: ");
    struct Node* current = deque->front;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    insertFront(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);

    display(&deque);

    printf("Removed from the front: %d\n", removeFront(&deque));
    printf("Removed from the rear: %d\n", removeRear(&deque));

    display(&deque);

    return 0;
}
