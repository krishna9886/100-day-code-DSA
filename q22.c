#include <stdio.h>
#include <stdlib.h>

// Define the structure using lowercase 'node' consistently
struct node {
    int data;
    struct node* next;
};

int main() {
    int n;
    printf("Enter the no. of nodes you want: ");
    
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    struct node *head = NULL, *temp = NULL; 

    for (int i = 1; i <= n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter the %d node data: ", i);
        int val;
        scanf("%d", &val); 
        
        // Assign the input value to the node
        newNode->data = val; 
        newNode->next = NULL;

        if (head == NULL) {
            // First node becomes the head
            head = newNode;
            temp = head;
        } else {
            // Hitch the new node to the end of the existing chain
            temp->next = newNode;
            // Move temp forward to stay on the last node
            temp = newNode; 
        }
    }

    

    // --- Part 1: Printing the list ---
    printf("\nYour Linked List: ");
    struct node* current = head; // Declare 'current' once
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");

    // --- Part 2: Counting the nodes ---
    int count = 0;
    current = head; // Reset 'current' to the start (don't redeclare it)
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Total node count: %d\n", count);

    // --- Part 3: Memory Cleanup (Best Practice) ---
    current = head;
    while (current != NULL) {
        struct node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}