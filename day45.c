// Day 45 - Height of a Binary Tree
// Problem: Find the height (maximum depth) of a given binary tree

#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate height of binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Return max of left and right height + 1 for current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Queue structure for level-order construction
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

// Create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Add node to queue
void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

// Remove node from queue
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    
    struct QueueNode* temp = q->front;
    struct Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return treeNode;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Build tree from level order traversal
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    
    struct Node* root = createNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);
    
    int i = 1;
    while (i < n && !isEmpty(q)) {
        struct Node* current = dequeue(q);
        
        // Process left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;
        
        // Process right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = buildTree(arr, n);
    
    int h = height(root);
    printf("%d\n", h);
    
    free(arr);
    return 0;
}
