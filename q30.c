#include <stdio.h>
#include <stdlib.h>

// Define the Term node
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new term
struct Node* createTerm(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        // Print coefficient and x
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Print " + " only if there is a next term
        if (temp->next != NULL) {
            printf(" + ");
        }
        
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        struct Node* newNode = createTerm(c, e);
        
        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    displayPolynomial(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
