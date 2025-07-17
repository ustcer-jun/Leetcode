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

void Inorder(struct TreeNode* root,int*arr,int* index){
    if(!root){
        return;
    }
    Inorder(root->left,arr,index);
    arr[*index]=root->_val;
    (*index)++;
    Inorder(root->right,arr,index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root){
        * returnSize = 0;
        return NULL;
    } 
    int size = TreeSize(root);
    * returnSize = size;
    int* arr = (int*)malloc(sizeof(int)*size);
    int index = 0;
    Inorder(root,arr,&index);
    return arr;
}