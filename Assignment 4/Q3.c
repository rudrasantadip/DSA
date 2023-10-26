// 3 Function to insert at any position in the linked list



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

// Function to insert a value at a specific position in the merged list
struct Node* insert_at_position(struct Node* head, int position, int data) {
    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position is out of range.\n");
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
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
    struct Node* mergedList = NULL;

    // Merge two lists
    mergedList = mergeLinkedLists(mergedList, insert_end(NULL, 1));
    mergedList = mergeLinkedLists(mergedList, insert_end(NULL, 2));
    mergedList = mergeLinkedLists(mergedList, insert_end(NULL, 3));

    // Display the merged list
    printf("Merged List:\n");
    display(mergedList);

    // Insert a value at a specific position in the merged list
    int position = 2;
    int value = 4;
    mergedList = insert_at_position(mergedList, position, value);

    // Display the updated list
    printf("Updated List:\n");
    display(mergedList);

    // Free the memory for the merged list before exiting
    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
