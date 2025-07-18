#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL){ //停止条件当为空树
        return true;
    }
    if(!p || !q || p->_val != q->_val){ //判断如果两个节点有一个为空，或者两节点值不相等
        return false;
    }
    else{
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
}