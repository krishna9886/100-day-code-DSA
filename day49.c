/*
 * Day 49 - Question 1: BST Insert
 * Insert a new node with a given value into a Binary Search Tree
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/*
 * Create a new node with the given data
 */
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
 * Insert a new node into the BST
 * Returns the root of the modified BST
 */
Node* insert(Node* root, int data) {
    // If tree is empty, create a new node and return it
    if (root == NULL) {
        return newNode(data);
    }
    
    // If data is less than root's data, insert in left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If data is greater than root's data, insert in right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data is equal to root's data, don't insert (no duplicates)
    
    return root;
}

/*
 * In-order traversal of BST (Left, Root, Right)
 * This prints the elements in sorted order
 */
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/*
 * Main function to test BST insertion
 */
int main() {
    Node* root = NULL;
    int n, value;
    
    // Read number of elements to insert
    scanf("%d", &n);
    
    // Insert elements into BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    // Print in-order traversal (should be sorted)
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
