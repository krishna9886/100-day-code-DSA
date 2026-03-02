#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the list
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0) return head;

    struct Node* tail = head;
    int n = 1;

    // 1. Calculate length and find the current tail
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    // 2. Adjust k in case k > n
    k = k % n;
    if (k == 0) return head;

    // 3. Connect tail to head to make it circular
    tail->next = head;

    // 4. Find the node before the new head
    // The new head will be at (n - k) from the start
    int stepsToNewTail = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // 5. Set new head and break the circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, val;
    
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL;

    // Input elements and build the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print the rotated list
    temp = head;
    while (temp) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    // Clean up memory
    while (head) {
        struct Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}