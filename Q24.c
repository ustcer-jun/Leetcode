#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct {
    int* arr;
    int head;
    int rear;
    int K;
    
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k){
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(obj ==  NULL){
        perror("malloc");
        exit(-1);
    }
    obj->arr = (int*) malloc((k+1)* sizeof(int));
    obj->head = obj->rear = 0;
    obj->K = k;
    
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    assert(obj);
    if(obj->head == obj->rear){
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    assert(obj);
    if((obj->rear+1)%(obj->K+1) == obj->head){
        return true;
    }
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    assert(obj);
    if(myCircularQueueIsFull(obj)){
        return false;
    }
    obj->arr[obj->rear] = value; 
    ++obj->rear;                   
    if(obj->rear>obj->K){
        obj->rear = 0;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    assert(obj);
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    // free(obj->arr+(obj->rear-1));
    ++obj->head;  
    if(obj->head>obj->K){
        obj->head = 0;
    }   
    return true;  
}

int myCircularQueueFront(MyCircularQueue* obj) {
    assert(obj);
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    else{
        return obj->arr[obj->head];
    }
    
}

int myCircularQueueRear(MyCircularQueue* obj) {
    assert(obj);
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    else{
        return obj->arr[obj->rear-1];
    }
}


void myCircularQueueFree(MyCircularQueue* obj) {
    assert(obj);
    free(obj->arr);
    obj->arr = NULL;
    free(obj);
    obj = NULL;  
}
