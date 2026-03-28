#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Helper function to check if two trees are mirror images
bool isMirror(struct Node* root1, struct Node* root2) {
    // If both are NULL, they are mirrors
    if (root1 == NULL && root2 == NULL)
        return true;
    
    // If only one is NULL, they are not mirrors
    if (root1 == NULL || root2 == NULL)
        return false;
    
    // Check if current nodes have same data and
    // left subtree of root1 mirrors right subtree of root2
    // and right subtree of root1 mirrors left subtree of root2
    return (root1->data == root2->data) &&
           isMirror(root1->left, root2->right) &&
           isMirror(root1->right, root2->left);
}

// Function to check if a binary tree is symmetric
bool isSymmetric(struct Node* root) {
    // Empty tree is symmetric
    if (root == NULL)
        return true;
    
    // Check if left and right subtrees are mirrors
    return isMirror(root->left, root->right);
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
    
    if (isSymmetric(root))
        printf("Symmetric\n");
    else
        printf("Not Symmetric\n");
    
    return 0;
}
