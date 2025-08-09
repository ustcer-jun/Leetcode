#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef char BTDataType; 

typedef struct TreeNode {
    BTDataType _val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode* CreatTree(BTDataType* str,int* pi){
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    if(str[*pi] == '#'){
        (*pi)++;
        return NULL;
    }
    else{
        root->_val = str[*pi];
        (*pi)++;
        root->left = CreatTree(str,pi);
        root->right = CreatTree(str,pi);
    }
    return root;
 }
 void InOrder(TreeNode* root){
    if(!root){
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%c ",root->_val);
    InOrder(root->right);
}

   
int main(){
    char str[100] = {0};
    scanf("%s",str);
    int i =0;
    TreeNode* root = CreatTree(str,&i);
    InOrder(root);
}

