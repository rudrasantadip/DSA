// Write a C program to count the number of zeros in a circular linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the circular linked list
struct Node* insert_end(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode; // Circular reference to itself
        return newNode;
    }

    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

// Function to count the number of non-zero values in the circular linked list
int countNonZeroValues(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    if (current == NULL) {
        return count; // Return 0 if the list is empty
    }

    do {
        if (current->data != 0) {
            count++;
        }
        current = current->next;
    } while (current != head);

    return count;
}

// Function to display the circular linked list
void display(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;

    // Populate the circular linked list with integer values
    head = insert_end(head, 1);
    head = insert_end(head, 0);
    head = insert_end(head, -3);
    head = insert_end(head, 0);
    head = insert_end(head, 5);

    // Display the circular linked list
    printf("Circular Linked List:\n");
    display(head);

    // Count the number of non-zero values in the circular linked list
    int count = countNonZeroValues(head);
    printf("The number of non-zero values in the circular linked list is %d\n", count);

    // Free the memory for the circular linked list before exiting
    struct Node* current = head;
    do {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head);

    return 0;
}
