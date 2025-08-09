#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int BThDepth(struct TreeNode* root){
    if(!root){
        return 0;
    };
    int LeftDepth = BThDepth(root->left);
    int RightDepth =BThDepth(root->right);
    return LeftDepth > RightDepth ? LeftDepth+1 : RightDepth+1;
}

bool isBalanced(struct TreeNode* root) {
    if(BThDepth(root->left)-BThDepth(root->right) >1 ||BThDepth(root->left)-BThDepth(root->right) < -1){
        return false;
    }
    if(!root){
        return true;
    }
    return isBalanced(root->left)&&isBalanced(root->right);
}

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 返回树高，如果发现某子树不平衡则直接返回 -1
int checkBalance(struct TreeNode* root) {
    if (!root) return 0;

    int leftDepth = checkBalance(root->left);
    if (leftDepth == -1) return -1;  // 左子树不平衡，直接返回

    int rightDepth = checkBalance(root->right);
    if (rightDepth == -1) return -1; // 右子树不平衡，直接返回

    if (abs(leftDepth - rightDepth) > 1) return -1; // 当前节点不平衡
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return checkBalance(root) != -1;
}