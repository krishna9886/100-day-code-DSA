#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 2. Helper function to create a new "box" (node) for a number
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, val;
    Node *list1 = NULL, *list2 = NULL, *temp = NULL;

    // 3. Get first list from user
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        Node* newNode = createNode(val);
        if (list1 == NULL) {
            list1 = newNode;
            temp = list1;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // 4. Get second list from user
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        Node* newNode = createNode(val);
        if (list2 == NULL) {
            list2 = newNode;
            temp = list2;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // 5. MERGE LOGIC: The "Dummy" Start
    Node dummy; 
    Node* last = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            last->next = list1;   // Connect the smaller one
            list1 = list1->next; // Move the list1 finger forward
        } else {
            last->next = list2;   // Connect the smaller one
            list2 = list2->next; // Move the list2 finger forward
        }
        last = last->next;       // Move the merged list finger forward
    }

    // 6. Attach whatever is left over
    if (list1 != NULL) last->next = list1;
    else last->next = list2;

    // 7. Print the result (starting from dummy.next)
    Node* current = dummy.next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}