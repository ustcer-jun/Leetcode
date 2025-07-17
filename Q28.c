#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int Treesize(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1+Treesize(root->left)+Treesize(root->right);
}

void PreOrder(struct TreeNode* root,int* array,int* index){
    if(root == NULL){
        return;
    };
    array[*index] = root->_val;
    (*index)++;
    PreOrder(root->left,array,index);
    PreOrder(root->right,array,index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    int size = Treesize(root);
    *returnSize = size;
    int* array = (int*)malloc(size*sizeof(int));
    int index = 0;
    PreOrder(root,array,&index);
    return array;
}