#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Structure for queue (for level order traversal)
typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

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

// Queue operations
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

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
        
        if (i < n) {
            current->left = createNode(arr[i]);
            if (current->left != NULL)
                enqueue(q, current->left);
            i++;
        }
        
        if (i < n) {
            current->right = createNode(arr[i]);
            if (current->right != NULL)
                enqueue(q, current->right);
            i++;
        }
    }
    
    return root;
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* root = buildTree(arr, n);
    
    // Print all three traversals
    inorder(root);
    printf("\n");
    
    preorder(root);
    printf("\n");
    
    postorder(root);
    printf("\n");
    
    free(arr);
    return 0;
}
