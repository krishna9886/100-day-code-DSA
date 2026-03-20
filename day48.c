// Day 48 - Question 1: Count Leaf Nodes in a Binary Tree
// Problem: Count the number of leaf nodes in a binary tree
// Approach: Recursive - a leaf node has no left and right children

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count the number of leaf nodes
int countLeafNodes(Node* root) {
    // Base case: empty tree has 0 leaf nodes
    if (root == NULL) {
        return 0;
    }
    
    // If this node is a leaf node (no left and right children)
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // Recursively count leaf nodes in left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Driver code to test
int main() {
    // Constructing a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //       /
    //      6
    
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    
    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));
    
    return 0;
}
