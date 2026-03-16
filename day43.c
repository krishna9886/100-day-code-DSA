#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Structure for queue node
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

// Structure for queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Create a new tree node
Node* createNode(int data) {
    if (data == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue operation
void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue operation
Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return treeNode;
}

// Build tree from level order traversal
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    Node* root = createNode(arr[0]);
    Queue* q = createQueue();
    enqueue(q, root);
    
    int i = 1;
    while (i < n && !isEmpty(q)) {
        Node* current = dequeue(q);
        
        // Add left child
        if (i < n) {
            current->left = createNode(arr[i]);
            if (current->left != NULL)
                enqueue(q, current->left);
            i++;
        }
        
        // Add right child
        if (i < n) {
            current->right = createNode(arr[i]);
            if (current->right != NULL)
                enqueue(q, current->right);
            i++;
        }
    }
    
    return root;
}

// Inorder traversal (for output)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    inorder(root);
    printf("\n");
    
    free(arr);
    return 0;
}
