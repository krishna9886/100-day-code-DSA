#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return value;
}

int main() {
    int n;
    scanf("%d", &n);
    
    Queue* q = createQueue();
    
    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);
        
        if (op == 1) {  // Enqueue
            int value;
            scanf("%d", &value);
            enqueue(q, value);
        } else if (op == 2) {  // Dequeue
            int result = dequeue(q);
            printf("%d\n", result);
        }
    }
    
    // Free remaining nodes
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
    
    return 0;
}
