#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("enter the number of nodes u want to create:");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 1; i <= n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("enter the %d node: ",i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            // First node becomes the head
            head = newNode;
            temp = head;
        } else {
            // Link the previous node to the new node
            temp->next = newNode;
            temp = newNode; // Move temp to the new last node
        }
    }

    // Traversal: Start from the head and print each element
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" "); // Print space between elements
        }
        current = current->next;
    }
    printf("\n");

    // Clean up memory
    current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}