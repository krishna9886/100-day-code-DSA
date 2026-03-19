// Day 47 - Question 1: Height of Binary Tree
// Problem: Find the height of a Binary Tree
// Approach: Recursive - height = 1 + max(height(left), height(right))

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

// Function to find the height of the binary tree
int heightOfBinaryTree(Node* root) {
    // Base case: empty tree has height 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively find height of left and right subtrees
    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);
    
    // Return 1 + max of left and right heights
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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
    
    printf("Height of the Binary Tree: %d\n", heightOfBinaryTree(root));
    
    return 0;
}
