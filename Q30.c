#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int TreeSize(struct TreeNode* root){
    if(!root){
        return 0;
    }
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

void PostOrder(struct TreeNode* root,int*arr,int* index){
    if(!root){
        return;
    }
    PostOrder(root->left,arr,index);
    PostOrder(root->right,arr,index);
    arr[*index]=root->_val;
    (*index)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root){
        * returnSize = 0;
        return NULL;
    } 
    int size = TreeSize(root);
    * returnSize = size;
    int* arr = (int*)malloc(sizeof(int)*size);
    int index = 0;
    PostOrder(root,arr,&index);
    return arr;
}