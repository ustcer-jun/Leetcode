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

// bool isUnivalTree(struct TreeNode* root){
//     if(root == NULL){
//         return true;
//     }
//     if(root->left && root->left->_val != root->_val){
//         return false;
//     }
//     if(root->right && root->right->_val != root->_val){
//         return false;
//     }
    
//     return isUnivalTree(root->left) && isUnivalTree(root->right);

// }

bool isUnivalTree(struct TreeNode* root){
    if(root == NULL){
        return true;
    }
    int val = root->_val;
    struct TreeNode** my_queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*100);
    //节点数小于100；
    int front = 0; int rear = 0;
    my_queue[rear++] = root;
    while (front<rear) //当遍历完全部的节点时
    {
        struct TreeNode* node = my_queue[front++]; 
        if(node->_val != val){
            return false;
        }
        if(node->left){
            my_queue[rear++] = node->left;//通过这种方式放入的数据是层序的。
        }
        if (node->right)
        {
            my_queue[rear++] = node->right;
        }
    }
    free(my_queue);
    my_queue = NULL;
    return true;
}


int main(){
    struct TreeNode* root = BuyNewNode(1);
    root->left = BuyNewNode(1);
    root->right = BuyNewNode(1);
    (root->right)->left = BuyNewNode(1);
    (root->right)->right = BuyNewNode(1);
    (root->left)->left = BuyNewNode(0);
    if (isUnivalTree(root)){
        printf("Yes!\n");
    }
    free(root);
    root = NULL;
}