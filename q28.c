#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    
    // Read the number of elements
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0; // Exit if input is invalid or list is empty
    }
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    // Build the linked list
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = createNode(val);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Make the list circular by pointing tail's next to head
    if (tail != NULL) {
        tail->next = head;
    }
    
    // Traverse and print the circular linked list
    if (head != NULL) {
        struct Node* curr = head;
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != head); // Stop when we wrap around to the head
        printf("\n");
    }
    
    // Clean up allocated memory
    if (head != NULL) {
        // Break the circle first to easily free the list
        tail->next = NULL; 
        
        struct Node* curr = head;
        while (curr != NULL) {
            struct Node* nextNode = curr->next;
            free(curr);
            curr = nextNode;
        }
    }

    return 0;
}