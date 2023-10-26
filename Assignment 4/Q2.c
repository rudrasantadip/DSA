// Write a program to merge the linked list of the same type without using a third linked list


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

// Function to merge the second linked list into the first linked list
struct Node* mergeLinkedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;

    return list1;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Populate the first list
    list1 = insert_end(list1, 1);
    list1 = insert_end(list1, 2);
    list1 = insert_end(list1, 3);

    // Populate the second list
    list2 = insert_end(list2, 4);
    list2 = insert_end(list2, 5);
    list2 = insert_end(list2, 6);

    // Display both lists before merging
    printf("List 1:\n");
    display(list1);
    printf("List 2:\n");
    display(list2);

    // Merge the second list into the first list
    list1 = mergeLinkedLists(list1, list2);

    // Display the merged list
    printf("Merged List:\n");
    display(list1);

    // Free the memory for the lists before exiting
    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }

    return 0;
}
