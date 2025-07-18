#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct TreeNode {
    int _val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* BuyNewNode(int val){
    struct TreeNode* NewNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    NewNode->_val = val;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
};

void Swap(struct TreeNode* left,struct TreeNode* right){
    struct TreeNode tmp = *left;
    *left = *right;
    *right = tmp;
}

struct TreeNode* invertTree(struct TreeNode* root){
    if(!root){
        return NULL;
    }
    else{
        struct TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
}


int main(){
    struct TreeNode* Root = BuyNewNode(1);
    Root->left = BuyNewNode(2);
    Root->right = BuyNewNode(3);
    (Root->left)->left = BuyNewNode(4);
    (Root->left)->right = BuyNewNode(5);
    (Root->left)->left->left = BuyNewNode(6);
    printf("%d\n",maxDepth(Root));
}