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

// Function to mirror a binary tree
struct Node* mirror(struct Node* root) {
    if (root == NULL)
        return NULL;
    
    // Recursively mirror left and right subtrees
    struct Node* left = mirror(root->left);
    struct Node* right = mirror(root->right);
    
    // Swap left and right children
    root->left = right;
    root->right = left;
    
    return root;
}

// Function to print inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    
    printf("Original Inorder: ");
    inorder(root);
    printf("\n");
    
    root = mirror(root);
    
    printf("Mirrored Inorder: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
