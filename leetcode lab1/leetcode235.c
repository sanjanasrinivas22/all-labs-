#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return NULL;
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;  // If one node is on the left and the other is on the right, root is LCA
    }
}

int main() {
    // Example usage with custom tree nodes
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 6;
    
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = 2;
    
    struct TreeNode* q = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q->val = 8;

    struct TreeNode* ancestor = lowestCommonAncestor(root, p, q);
    printf("Lowest Common Ancestor: %d\n", ancestor->val);

    return 0;
}
