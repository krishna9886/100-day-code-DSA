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

// Function to search for a key in BST
struct Node* searchBST(struct Node* root, int key) {
    // Base case: root is null or key is at root
    if (root == NULL || root->data == key)
        return root;
    
    // Key is greater than root's data, search in right subtree
    if (key > root->data)
        return searchBST(root->right, key);
    
    // Key is smaller than root's data, search in left subtree
    return searchBST(root->left, key);
}

int main() {
    struct Node* root = NULL;
    int n, data, key;
    
    // Input: number of nodes
    scanf("%d", &n);
    
    // Input: node values to build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    // Input: key to search
    scanf("%d", &key);
    
    // Search for the key
    struct Node* result = searchBST(root, key);
    
    if (result != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");
    
    return 0;
}
