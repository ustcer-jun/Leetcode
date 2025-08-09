#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool ismirrortree(struct TreeNode* p,struct TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    if(!p || !q || p->val != q->val){
        return false;
    }
    return ismirrortree(p->left,q->right) && ismirrortree(p->right,q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(!root){
        return true;
    }
    return ismirrortree(root->left,root->right);
}