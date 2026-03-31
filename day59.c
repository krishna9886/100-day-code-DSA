#include <stdio.h>
#include <stdlib.h>

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

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;
    
    struct TreeNode* node = createNode(postorder[*postIndex]);
    (*postIndex)--;
    
    if (inStart == inEnd)
        return node;
    
    int inIndex = search(inorder, inStart, inEnd, node->data);
    
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    
    return node;
}

void preorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int inorder[n], postorder[n];
    
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    
    int postIndex = n - 1;
    struct TreeNode* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);
    
    preorder(root);
    printf("\n");
    
    return 0;
}
