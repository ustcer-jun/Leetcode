#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
#define Init_Capcity 4
typedef struct Stack
{
    STDataType* arr;
    int size;
    int capacity;
}Stack;

Stack* Stack_init(){
    Stack* ST = (Stack*) malloc(sizeof(Stack));
    if(ST == NULL){
        perror("Mallo!");
        exit(-1);
    }
    ST->arr = (STDataType*) malloc(Init_Capcity*sizeof(int));
    ST->size =0;
    ST->capacity = Init_Capcity;
    return ST;
}
void Stack_Destroy(Stack* st){
    assert(st);
    free(st->arr);
    st->arr =NULL;
    // st->size =st->capacity = 0;
    free(st);
    st = NULL;
}
void StackPush(Stack* st,STDataType Val){
    assert(st);
    if(st->size == st->capacity){
        //增容
        st->capacity = 2*st->capacity;
        STDataType* tmp = (STDataType*) realloc(st->arr,st->capacity*sizeof(int));
        st->arr =  tmp; 
        tmp = NULL;
    }
    st->arr[st->size] = Val;
    st->size++;
}
void StackPop(Stack* st){
    assert(st && st->size>0);
    st->size--;
}

int StackSize(Stack* st){
    assert(st);
    return st->size;
}

int StackEmpty(Stack* st){
    assert(st);
    
    return  !(st->size);
}
STDataType StackTop(Stack* st){
    assert(st && st->size>0);
    int ret = st->arr[st->size-1];
    return ret;
}

typedef struct {
    Stack* Push_ST;
    Stack* Pop_ST;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*) malloc(sizeof(MyQueue));
    obj->Push_ST = Stack_init();
    obj->Pop_ST = Stack_init();
    return obj;
}

void myQueuePush(MyQueue* obj, int x){
    assert(obj);
    StackPush(obj->Push_ST,x); 
}

int myQueuePeek(MyQueue* obj) {
    assert(obj);
    if(!StackEmpty(obj->Push_ST)){
        while (!StackEmpty(obj->Push_ST))
        {
            StackPush(obj->Pop_ST,StackTop(obj->Push_ST));
            StackPop(obj->Push_ST);
        }
    }
    int ret = StackTop(obj->Pop_ST);
    return ret;
}

int myQueuePop(MyQueue* obj) {
    int ret = myQueuePeek(obj);
    StackPop(obj->Pop_ST);
    return ret;
}



bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    return (StackEmpty(obj->Push_ST) && StackEmpty(obj->Pop_ST));
}

void myQueueFree(MyQueue* obj) {
    assert(obj);
    Stack_Destroy(obj->Pop_ST);
    Stack_Destroy(obj->Push_ST);
    obj->Pop_ST =NULL;
    obj->Push_ST =NULL;
    free(obj);
    obj = NULL;
}
int main() {
    MyQueue* q = myQueueCreate();
    myQueuePush(q, 1);
    myQueuePush(q, 2);
    myQueuePush(q, 3);
    
    printf("%d\n", myQueuePeek(q)); // 1
    printf("%d\n", myQueuePop(q));  // 1
    printf("%d\n", myQueuePop(q));  // 2
    printf("%d\n", myQueueEmpty(q)); // 0 (false)
    
    myQueueFree(q);
    return 0;
}