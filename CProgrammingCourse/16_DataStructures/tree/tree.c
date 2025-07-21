/***********************************************
* Name        : C Programmer (sanjeet8.23@gmail.com)
* Description : Tree 
* Date        : 12th July 2025
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Create a new node
TreeNode* tree_createNode(int value) {
    printf("[Create] New node created with value %d\n", value);
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
TreeNode* tree_insert(TreeNode* root, int value) {
    if (root == NULL) {
        printf("[Insert] Inserting %d at root\n", value);
        return tree_createNode(value);
    }

    if (value < root->data) {
        printf("[Insert] %d < %d->going left\n", value, root->data);
        root->left = tree_insert(root->left, value);
    } else {
        printf("[Insert] %d >= %d->going right\n", value, root->data);
        root->right = tree_insert(root->right, value);
    }

    return root;
}

// Inorder traversal
void tree_inorder(TreeNode* root) {
    if (root != NULL) {
        tree_inorder(root->left);
        printf("[Inorder] Visiting node: %d\n", root->data);
        tree_inorder(root->right);
    }
}

// Preorder traversal
void tree_preorder(TreeNode* root) {
    if (root != NULL) {
        printf("[Preorder] Visiting node: %d\n", root->data);
        tree_preorder(root->left);
        tree_preorder(root->right);
    }
}

// Postorder traversal
void tree_postorder(TreeNode* root) {
    if (root != NULL) {
        tree_postorder(root->left);
        tree_postorder(root->right);
        printf("[Postorder] Visiting node: %d\n", root->data);
    }
}

// Search a node
TreeNode* tree_search(TreeNode* root, int key) {
    printf("[Search] Looking for %d...\n", key);
    if (root == NULL) {
        printf("[Search] Not found.\n");
        return NULL;
    }

    if (root->data == key) {
        printf("[Search] Found %d!\n", key);
        return root;
    }

    if (key < root->data) {
        printf("[Search] %d < %d->going left\n", key, root->data);
        return tree_search(root->left, key);
    } else {
        printf("[Search] %d > %d->going right\n", key, root->data);
        return tree_search(root->right, key);
    }
}

// Find minimum
TreeNode* tree_findMin(TreeNode* root) {
    printf("[FindMin] Finding minimum...\n");
    while (root && root->left != NULL) {
        printf("[FindMin] Traversing left->current: %d\n", root->data);
        root = root->left;
    }
    if (root) printf("[FindMin] Found minimum: %d\n", root->data);
    return root;
}

// Find maximum
TreeNode* tree_findMax(TreeNode* root) {
    printf("[FindMax] Finding maximum...\n");
    while (root && root->right != NULL) {
        printf("[FindMax] Traversing right->current: %d\n", root->data);
        root = root->right;
    }
    if (root) printf("[FindMax] Found maximum: %d\n", root->data);
    return root;
}

// Delete a node
TreeNode* tree_deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        printf("[Delete] %d not found.\n", key);
        return NULL;
    }

    if (key < root->data) {
        printf("[Delete] %d < %d->going left\n", key, root->data);
        root->left = tree_deleteNode(root->left, key);
    } else if (key > root->data) {
        printf("[Delete] %d > %d->going right\n", key, root->data);
        root->right = tree_deleteNode(root->right, key);
    } else {
        printf("[Delete] Found node %d. Deleting...\n", key);
        if (root->left == NULL) {
            printf("[Delete] Node has right child only or no child.\n");
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            printf("[Delete] Node has left child only.\n");
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = tree_findMin(root->right);
        printf("[Delete] Node has two children. Replacing with inorder successor %d\n", temp->data);
        root->data = temp->data;
        root->right = tree_deleteNode(root->right, temp->data);
    }
    return root;
}

// Count total nodes
int tree_countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    int left = tree_countNodes(root->left);
    int right = tree_countNodes(root->right);
    int total = 1 + left + right;
    printf("[CountNodes] Node %d->Subtotal: %d\n", root->data, total);
    return total;
}

// Count leaf nodes
int tree_countLeaves(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        printf("[CountLeaves] Leaf: %d\n", root->data);
        return 1;
    }
    return tree_countLeaves(root->left) + tree_countLeaves(root->right);
}

// Calculate height
int tree_height(TreeNode* root) {
    if (root == NULL) return -1;
    int leftHeight = tree_height(root->left);
    int rightHeight = tree_height(root->right);
    int h = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    printf("[Height] Node %d->Height: %d\n", root->data, h);
    return h;
}

// Demo wrapper for tree operations
void runTreeDemo() {
    TreeNode* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
	printf("\n=== Binary Tree Demo Begins ===\n");

    printf("== Inserting Values ==\n");
    for (int i = 0; i < 7; i++)
        root = tree_insert(root, values[i]);

    printf("\n== Inorder Traversal ==\n");
    tree_inorder(root);

    printf("\n\n== Preorder Traversal ==\n");
    tree_preorder(root);

    printf("\n\n== Postorder Traversal ==\n");
    tree_postorder(root);

    printf("\n\n== Search Operation ==\n");
    tree_search(root, 60);

    printf("\n== Min & Max Values ==\n");
    tree_findMin(root);
    tree_findMax(root);

    printf("\n== Tree Properties ==\n");
    printf("Height: %d\n", tree_height(root));
    printf("Total Nodes: %d\n", tree_countNodes(root));
    printf("Leaf Nodes: %d\n", tree_countLeaves(root));

    printf("\n== Deletion ==\n");
    root = tree_deleteNode(root, 30);

    printf("\n== Inorder After Deletion ==\n");
    tree_inorder(root);
	printf("\n=== Binary Tree Demo Ends ===\n");
}