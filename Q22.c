#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QLDataType;

typedef struct QueueList
{
    int _val;
    struct QueueList* next;
}QueueList;
typedef struct Queue
{
    QueueList* _head;
    QueueList* _tail;
}Queue;

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;


//队列的基本操作的实现。

void QList_Init(Queue* pq){
    assert(pq);
    
    pq->_head = NULL;
    pq->_tail = NULL;
}

void QList_Destroy(Queue* pq){
    assert(pq);
    if(pq->_head == NULL){
        return;
    }
    QueueList* Cur = pq->_head;
    while (Cur)
    {
        QueueList* Next = Cur->next;
        free(Cur);
        Cur = Next;
    }
    pq->_head = NULL;
    pq->_tail = NULL;
}

//入队操作
void QList_Push(Queue* pq,QLDataType x){
    assert(pq);
    QueueList* NewNode = (QueueList*)malloc(sizeof(QueueList));
    if(NewNode == NULL){
        perror("MALLOC");
        exit(-1);
    }
    NewNode->_val = x;
    NewNode->next = NULL;
    if(pq->_head == NULL){
        pq->_head = pq->_tail= NewNode;
    }
    else{
        pq->_tail->next = NewNode;
        pq->_tail = NewNode;
    }
    return;
}
// 出队，先进先删
void QList_Pop(Queue* pq){
    assert(pq);
    if(pq->_head == NULL){
        printf("空队列！\n");
        return;
    }
    QueueList* head_next = pq->_head->next;
    free(pq->_head);
    pq->_head = head_next;
    if(pq->_head == NULL){
        pq->_tail = NULL;
    }
}
//取出队头数据“先进先出”
QLDataType QListFront(Queue* pq){
    assert(pq);
    if(pq->_head == NULL){
        printf("空队列！\n");
        return -1;
    }
    return (pq->_head->_val);
}

int QList_Empty(Queue* pq){
    assert(pq);
    return !(pq->_head);
}

int QListSize(Queue* pq){
    assert(pq);
    int count = 0;
    QueueList* Cur = pq->_head;
    while (Cur)
    {
        count++;
        Cur = Cur->next;
    }
    return count;
}


MyStack* myStackCreate(){
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    st->q1 = (Queue*)malloc(sizeof(Queue));
    st->q2 = (Queue*)malloc(sizeof(Queue));
    QList_Init(st->q1);
    QList_Init(st->q2);
    return st;
}
// 将元素 x 压入栈顶
void myStackPush(MyStack* obj, int x){
    assert(obj);
    if(!QList_Empty(obj->q1)){
        QList_Push(obj->q1,x);
    }
    else{
        QList_Push(obj->q2,x);
    }
}

//int pop() 移除并返回栈顶元素。
int myStackPop(MyStack* obj) {
    assert(obj);
    if(!QList_Empty(obj->q1)){
        while (QListSize(obj->q1)>1)
        {
            QList_Push(obj->q2,QListFront(obj->q1));
            QList_Pop(obj->q1);
        }
        int target = QListFront(obj->q1);
        QList_Pop(obj->q1);
        return target;
    }
    // else if(QList_Empty(obj->q1) && QList_Empty(obj->q2)){
    //     return -1;
    // }
    else{
        while (QListSize(obj->q2)>1)
        {
            QList_Push(obj->q1,QListFront(obj->q2));
            QList_Pop(obj->q2);
        }
        int target = QListFront(obj->q2);
        QList_Pop(obj->q2);
        return target;
    }
}

int myStackTop(MyStack* obj){
    assert(obj);
    if(!QList_Empty(obj->q1)){
        return (obj->q1)->_tail->_val;
    }
    else{
        return (obj->q2)->_tail->_val;
    }
}

bool myStackEmpty(MyStack* obj) {
    assert(obj);
    return !(QList_Empty(obj->q1) || QList_Empty(obj->q2));
}

void myStackFree(MyStack* obj) {
    assert(obj);
    QList_Destroy(obj->q1);
    QList_Destroy(obj->q2);
    free(obj->q1);
    free(obj->q2);
    obj = NULL;
}


