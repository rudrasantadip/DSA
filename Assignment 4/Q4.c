// 4 Write a C program to count the number of occurances of a value in a linked list

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
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

// Function to insert a new node at the end of the linked list
struct Node* insert_end(struct Node* head, int data) {
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

// Function to count the number of occurrences of a value in the linked list
int countOccurrences(struct Node* head, int value) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            count++;
        }
        current = current->next;
    }

    return count;
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
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Populate the linked list
    head = insert_end(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);
    head = insert_end(head, 2);
    head = insert_end(head, 4);
    head = insert_end(head, 2);

    // Display the linked list
    printf("Linked List:\n");
    display(head);

    // Value to count occurrences
    int value = 2;

    // Count the occurrences of the value in the linked list
    int occurrences = countOccurrences(head, value);
    printf("The value %d appears %d times in the linked list.\n", value, occurrences);

    // Free the memory for the linked list before exiting
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
