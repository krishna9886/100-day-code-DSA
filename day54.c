#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Structure for stack node
struct StackNode {
    struct Node* treeNode;
    struct StackNode* next;
};

// Stack structure
struct Stack {
    struct StackNode* top;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to push to stack
void push(struct Stack* stack, struct Node* node) {
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    temp->treeNode = node;
    temp->next = stack->top;
    stack->top = temp;
}

// Function to pop from stack
struct Node* pop(struct Stack* stack) {
    if (stack->top == NULL)
        return NULL;
    
    struct StackNode* temp = stack->top;
    struct Node* node = temp->treeNode;
    stack->top = stack->top->next;
    free(temp);
    return node;
}

// Function to check if stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to print zigzag level order traversal
void printZigZag(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Stack* currentLevel = createStack();
    struct Stack* nextLevel = createStack();
    
    push(currentLevel, root);
    bool leftToRight = true;
    
    while (!isEmpty(currentLevel)) {
        struct Node* temp = pop(currentLevel);
        printf("%d ", temp->data);
        
        if (leftToRight) {
            if (temp->left)
                push(nextLevel, temp->left);
            if (temp->right)
                push(nextLevel, temp->right);
        } else {
            if (temp->right)
                push(nextLevel, temp->right);
            if (temp->left)
                push(nextLevel, temp->left);
        }
        
        if (isEmpty(currentLevel)) {
            leftToRight = !leftToRight;
            struct Stack* tempStack = currentLevel;
            currentLevel = nextLevel;
            nextLevel = tempStack;
        }
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
    
    printf("Zigzag Traversal: ");
    printZigZag(root);
    
    return 0;
}
