#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root, int* leafs, int* index) {
    if (!root) return;
    if (!root->left && !root->right) {
        leafs[*index] = root->val;
        (*index)++;
    }
    dfs(root->left, leafs, index);
    dfs(root->right, leafs, index);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leafs1[100], leafs2[100];
    int index1 = 0, index2 = 0;
    dfs(root1, leafs1, &index1);
    dfs(root2, leafs2, &index2);
    
    if (index1 != index2) return false;
    for (int i = 0; i < index1; i++) {
        if (leafs1[i] != leafs2[i]) return false;
    }
    return true;
}

int main() {
    // Example usage with custom tree nodes
    struct TreeNode* root1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* root2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    // Initialize root1 and root2 tree nodes...
    
    if (leafSimilar(root1, root2)) {
        printf("Trees are leaf-similar.\n");
    } else {
        printf("Trees are not leaf-similar.\n");
    }
    
    return 0;
}
