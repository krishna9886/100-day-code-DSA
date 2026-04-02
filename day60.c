#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int index, int n) {
    if (index >= n || arr[index] == -1)
        return NULL;
    
    struct TreeNode* root = createNode(arr[index]);
    root->left = buildTree(arr, 2 * index + 1, n);
    root->right = buildTree(arr, 2 * index + 2, n);
    return root;
}

bool isMinHeap(struct TreeNode* root, int parentVal) {
    if (root == NULL)
        return true;
    
    if (root->data < parentVal)
        return false;
    
    return isMinHeap(root->left, root->data) && isMinHeap(root->right, root->data);
}

bool validateMinHeap(struct TreeNode* root) {
    if (root == NULL)
        return true;
    
    return isMinHeap(root->left, root->data) && isMinHeap(root->right, root->data);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    struct TreeNode* root = buildTree(arr, 0, n);
    
    if (validateMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
