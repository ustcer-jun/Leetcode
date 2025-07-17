//返回前k个最小的元素。利用大根堆。


void Swap(int* p1,int* p2){
    assert(p1 && p2);
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustDown(int* karr,int size, int root){
    assert(karr);
    int parent = root;
    int child = 2*parent+1;
    while(child<size){
        if(child+1<size && karr[child] < karr[child+1]){
            ++child;
        }
        if(karr[parent]<karr[child]){
            Swap(&karr[parent],&karr[child]);
            parent =child;
            child = 2*parent+1;
        }
        else{
            break;
        }
    }
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = k;
    if(k == 0){
        return NULL;
    }
    int* karr = (int*) malloc(sizeof(int)*k);
    //初始化
    for(int i = 0;i<k;i++){
        karr[i] = arr[i];
    }
    //构建大根堆
    for(int root = (k-1-1)/2;root>=0;root--){
        AdjustDown(karr,k,root);
    }
    // 比较数组元素和堆顶元素
    for(int j = k;j<arrSize;j++){
        if(karr[0]>arr[j]){
            karr[0] = arr[j];
            AdjustDown(karr,k,0);
        }
    }
    return karr;
}