#include <stdio.h>
#include <stdlib.h>

// 1. Blueprint for the train car
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Helper function to build a new car
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int main() {
    int n, i, val, key;
    Node *head = NULL, *tail = NULL;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    // Build the train
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        Node* new_node = create_node(val);
        
        if (head == NULL) { // If it's the very first car
            head = new_node;
            tail = new_node;
        } else {            // Attach to the end and move the tail sign
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Read the key we want to delete
    scanf("%d", &key);

    // --- DELETION LOGIC ---
    if (head != NULL) {
        // Scenario A: The very first car has the cargo we want to delete!
        if (head->data == key) {
            Node* car_to_scrap = head; 
            head = head->next;         // Move the 'head' sign to the 2nd car
            free(car_to_scrap);        // Demolish the 1st car
        } 
        // Scenario B: The cargo is somewhere in the middle or end
        else {
            Node* current = head;
            Node* prev = NULL;
            
            // Conductor walks down the train looking for the key
            while (current != NULL && current->data != key) {
                prev = current;          // Remember the car we are leaving
                current = current->next; // Step into the next car
            }
            
            // If the conductor actually found the car (didn't fall off the end)
            if (current != NULL) {
                // Unhook from the target car and bypass it to the next one
                prev->next = current->next; 
                free(current); // Demolish the target car
            }
        }
    }

    // Print the updated train
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Clean up the remaining train yard (Free memory)
    current = head;
    while (current != NULL) {
        Node* next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}