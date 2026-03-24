#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
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

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    
    return root;
}

// Function to find Lowest Common Ancestor in BST
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    
    // If both n1 and n2 are smaller than root, LCA lies in left subtree
    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
    
    // If both n1 and n2 are greater than root, LCA lies in right subtree
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);
    
    // If one is on left and other is on right, or one equals root, then root is LCA
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, data, n1, n2;
    
    // Input: number of nodes
    scanf("%d", &n);
    
    // Input: node values to build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    // Input: two nodes to find LCA
    scanf("%d %d", &n1, &n2);
    
    // Find LCA
    struct Node* lca = LCA(root, n1, n2);
    
    if (lca != NULL)
        printf("%d\n", lca->data);
    else
        printf("LCA not found\n");
    
    return 0;
}
