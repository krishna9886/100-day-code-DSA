#include <stdio.h>
#include <stdlib.h>

// Structure for binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Structure for queue node (for level order traversal)
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

// Queue structure
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue
void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    
    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return node;
}

// Function to check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to print level order traversal
void printLevelOrder(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Queue* q = createQueue();
    enqueue(q, root);
    
    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);
        
        if (current->left)
            enqueue(q, current->left);
        if (current->right)
            enqueue(q, current->right);
    }
    printf("\n");
}

// Helper function to build tree from array
struct Node* buildTree(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n && arr[i] != -1) {
        root = newNode(arr[i]);
        root->left = buildTree(arr, 2*i + 1, n);
        root->right = buildTree(arr, 2*i + 2, n);
    }
    return root;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    struct Node* root = buildTree(arr, 0, n);
    
    printf("Level Order Traversal: ");
    printLevelOrder(root);
    
    return 0;
}
