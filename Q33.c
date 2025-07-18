#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isSameTree(struct TreeNode* p,struct TreeNode* q){
    if(!p && !q){
        return true;
    }
    if(!p || !q || p->_val != q->_val){
        return false;
    }
    return(isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}

bool isSubTree(struct TreeNode* root,struct TreeNode* subroot){
    if(!root && !subroot){
        return true;
    }
    if(!root || !subroot){
        return false;
    }
    if(isSameTree(root,subroot)){
            return true;
    }
    return isSubTree(root->left,subroot) || isSubTree(root->right,subroot);
}
