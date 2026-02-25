#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Linked List Node in C
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next; 
    
    return count;
}
}

int main() {
    int n;
    
    // Read the number of nodes
    if (scanf("%d", &n) != 1) return 0; 
    
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Read the linked list elements
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = createNode(val);
        
        if (head == NULL) {
            // If list is empty, make the new node the head
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, append to the end and update the tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read the key to be counted
    int key;
    printf("Enter the key to count occurrences: ");
    scanf("%d", &key);

    // Count and print the result
    printf("Occurrences of %d: ", key);
    printf("%d\n", countOccurrences(head, key));

  
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current); // Use free() in C instead of delete
        current = nextNode;
    }

    return 0;
}