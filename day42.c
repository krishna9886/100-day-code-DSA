#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Structure for stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push operation
void push(Stack* stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop operation
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    StackNode* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

// Structure for queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Check if queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Enqueue operation
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Dequeue operation
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    
    QueueNode* temp = queue->front;
    int dequeued = temp->data;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return dequeued;
}

// Reverse queue using stack
void reverseQueue(Queue* queue) {
    Stack* stack = createStack();
    
    // Transfer all elements from queue to stack
    while (!isQueueEmpty(queue)) {
        push(stack, dequeue(queue));
    }
    
    // Transfer all elements back from stack to queue
    while (!isEmpty(stack)) {
        enqueue(queue, pop(stack));
    }
    
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    
    Queue* queue = createQueue();
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        enqueue(queue, num);
    }
    
    reverseQueue(queue);
    
    // Print reversed queue
    while (!isQueueEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");
    
    return 0;
}
