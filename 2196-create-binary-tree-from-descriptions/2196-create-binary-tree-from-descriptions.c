#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Provided by LeetCode:
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    // Map from value -> TreeNode*
    // Since values are <= 1e5, we can use an array instead of a hash map
    struct TreeNode** nodes = (struct TreeNode**)calloc(100001, sizeof(struct TreeNode*));
    int* hasParent = (int*)calloc(100001, sizeof(int));

    for (int i = 0; i < descriptionsSize; i++) {
        int parent = descriptions[i][0];
        int child = descriptions[i][1];
        int isLeft = descriptions[i][2];

        // Create parent if not exists
        if (!nodes[parent]) {
            nodes[parent] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[parent]->val = parent;
            nodes[parent]->left = NULL;
            nodes[parent]->right = NULL;
        }
        // Create child if not exists
        if (!nodes[child]) {
            nodes[child] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            nodes[child]->val = child;
            nodes[child]->left = NULL;
            nodes[child]->right = NULL;
        }

        // Link child
        if (isLeft) {
            nodes[parent]->left = nodes[child];
        } else {
            nodes[parent]->right = nodes[child];
        }

        // Mark child as having a parent
        hasParent[child] = 1;
    }

    // Find root (the one that never appears as a child)
    struct TreeNode* root = NULL;
    for (int i = 0; i < descriptionsSize; i++) {
        int parent = descriptions[i][0];
        if (!hasParent[parent]) {
            root = nodes[parent];
            break;
        }
    }

    free(nodes);
    free(hasParent);
    return root;
}
