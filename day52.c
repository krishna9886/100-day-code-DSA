#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a binary tree node
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

// Helper function to find path from root to given node
bool findPath(struct Node* root, int n, int path[], int* pathLen) {
    if (root == NULL)
        return false;
    
    // Add current node to path
    path[(*pathLen)++] = root->data;
    
    // If current node is the target, return true
    if (root->data == n)
        return true;
    
    // Recursively search in left and right subtrees
    if (findPath(root->left, n, path, pathLen) || 
        findPath(root->right, n, path, pathLen))
        return true;
    
    // If not found in either subtree, remove current node from path
    (*pathLen)--;
    return false;
}

// Function to find LCA in Binary Tree
int findLCA(struct Node* root, int n1, int n2) {
    int path1[1000], path2[1000];
    int len1 = 0, len2 = 0;
    
    // Find paths to both nodes
    if (!findPath(root, n1, path1, &len1) || 
        !findPath(root, n2, path2, &len2))
        return -1; // One or both nodes not found
    
    // Find LCA by comparing paths
    int i;
    for (i = 0; i < len1 && i < len2; i++) {
        if (path1[i] != path2[i])
            break;
    }
    
    return path1[i-1];
}

// Function to insert nodes in level order (for testing)
struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n && arr[i] != -1) {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2*i + 1, n);
        root->right = insertLevelOrder(arr, 2*i + 2, n);
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
    
    struct Node* root = insertLevelOrder(arr, 0, n);
    
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    
    int lca = findLCA(root, n1, n2);
    
    if (lca != -1)
        printf("%d\n", lca);
    else
        printf("LCA not found\n");
    
    return 0;
}
