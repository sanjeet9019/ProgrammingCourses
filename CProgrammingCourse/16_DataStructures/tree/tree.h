#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* tree_createNode(int value);
TreeNode* tree_insert(TreeNode* root, int value);
void tree_inorder(TreeNode* root);
void tree_preorder(TreeNode* root);
void tree_postorder(TreeNode* root);
TreeNode* tree_search(TreeNode* root, int key);
TreeNode* tree_findMin(TreeNode* root);
TreeNode* tree_findMax(TreeNode* root);
TreeNode* tree_deleteNode(TreeNode* root, int key);
int tree_countNodes(TreeNode* root);
int tree_countLeaves(TreeNode* root);
int tree_height(TreeNode* root);
void runTreeDemo();

#endif // TREE_H