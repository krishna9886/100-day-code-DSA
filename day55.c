#include <stdio.h>
#include <stdlib.h>

// Structure for binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Helper function to print right view using recursion
void printRightViewUtil(struct Node* root, int level, int* maxLevel) {
    if (root == NULL)
        return;
    
    // If this is the first node of its level
    if (*maxLevel < level) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    
    // Recur for right subtree first, then left subtree
    printRightViewUtil(root->right, level + 1, maxLevel);
    printRightViewUtil(root->left, level + 1, maxLevel);
}

// Function to print right view of binary tree
void printRightView(struct Node* root) {
    int maxLevel = 0;
    printRightViewUtil(root, 1, &maxLevel);
    printf("\n");
}

// Helper function to build tree from array (level order)
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
    
    printf("Right View: ");
    printRightView(root);
    
    return 0;
}
