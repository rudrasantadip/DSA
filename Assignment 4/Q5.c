// Write a program to insert floating point numbers in a linked list and find their sum


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    float data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insert_end(struct Node* head, float data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to calculate the sum of floating-point numbers in the linked list
float calculateSum(struct Node* head) {
    float sum = 0.0;
    struct Node* current = head;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    return sum;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL) {
        printf("%.2f -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Populate the linked list with floating-point numbers
    head = insert_end(head, 1.5);
    head = insert_end(head, 2.3);
    head = insert_end(head, 3.7);
    head = insert_end(head, 4.2);

    // Display the linked list
    printf("Linked List:\n");
    display(head);

    // Calculate the sum of floating-point numbers in the linked list
    float sum = calculateSum(head);
    printf("The sum of numbers in the linked list is %.2f\n", sum);

    // Free the memory for the linked list before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
