#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int val;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to get the length of a linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Core Algorithm: Find the intersection node using length difference
struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Advance pointer in the longer list by the difference in lengths
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // Traverse both simultaneously to find the exact shared memory node
    while (headA != NULL && headB != NULL) {
        if (headA == headB) { // Pointer comparison (memory address)
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL;
}

int main() {
    int n, m;

    // 1. Read the first array
    if (scanf("%d", &n) != 1) return 0;
    int* A = (int*)malloc(n * sizeof(int));
    for (int k = 0; k < n; k++) {
        scanf("%d", &A[k]);
    }

    // 2. Read the second array
    if (scanf("%d", &m) != 1) return 0;
    int* B = (int*)malloc(m * sizeof(int));
    for (int k = 0; k < m; k++) {
        scanf("%d", &B[k]);
    }

    // 3. Find the starting index of the common suffix (to simulate shared memory)
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0 && A[i] == B[j]) {
        i--;
        j--;
    }
    
    // The intersection starts at A[i+1] and B[j+1]
    struct Node* headA = NULL;
    struct Node* tailA = NULL;
    struct Node* intersectNode = NULL;

    // 4. Build List A entirely
    for (int k = 0; k < n; k++) {
        struct Node* newNode = createNode(A[k]);
        if (headA == NULL) {
            headA = newNode;
        } else {
            tailA->next = newNode;
        }
        tailA = newNode;

        // Capture the physical memory address where intersection begins
        if (k == i + 1) {
            intersectNode = newNode;
        }
    }
    
    // Edge case: Lists are completely identical
    if (i == -1 && n > 0) {
        intersectNode = headA;
    }

    // 5. Build List B (only the unique prefix part)
    struct Node* headB = NULL;
    struct Node* tailB = NULL;
    for (int k = 0; k <= j; k++) {
        struct Node* newNode = createNode(B[k]);
        if (headB == NULL) {
            headB = newNode;
        } else {
            tailB->next = newNode;
        }
        tailB = newNode;
    }

    // 6. Connect List B's tail to List A's intersection node
    if (intersectNode != NULL) {
        if (tailB != NULL) {
            tailB->next = intersectNode;
        } else {
            headB = intersectNode; // List B is entirely a suffix of List A
        }
    }

    // 7. Run the standard algorithm on the connected lists
    struct Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        printf("%d\n", intersection->val);
    } else {
        printf("No Intersection\n");
    }

    // Clean up dynamically allocated arrays
    free(A);
    free(B);
    
    return 0;
}