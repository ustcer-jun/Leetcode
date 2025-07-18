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

int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int left_Depth = maxDepth(root->left);
    int right_Depth = maxDepth(root->right);
    return 1+(left_Depth > right_Depth ? left_Depth :right_Depth);
}

int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int left_Depth = maxDepth(root->left);
    int right_Depth = maxDepth(root->right);
    return maxDepth(root->left) > maxDepth(root->right) ? 1+maxDepth(root->left) : 1+maxDepth(root->right);
}//重复的递归计算，已经找出来root->left和root->right，但是又进行重复的计算了

int main(){
    struct TreeNode* Root = BuyNewNode(1);
    Root->left = BuyNewNode(2);
    Root->right = BuyNewNode(3);
    (Root->left)->left = BuyNewNode(4);
    (Root->left)->right = BuyNewNode(5);
    (Root->left)->left->left = BuyNewNode(6);
    printf("%d\n",maxDepth(Root));
}



//利用广度优先搜索方法+队列实现
#include <stdio.h>
#include <stdlib.h>


// 定义队列结构
typedef struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, struct TreeNode* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear) q->rear->next = newNode;
    else q->front = newNode;
    q->rear = newNode;
}

struct TreeNode* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = temp->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

// BFS 算法求最大深度
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    Queue* q = createQueue();
    enqueue(q, root);
    int depth = 0;
    while (!isEmpty(q)) {
        int levelSize = 0;
        QueueNode* temp = q->front;
        while (temp) {
            levelSize++;
            temp = temp->next;
        }

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        depth++;
    }
    return depth;
}