#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

bool isValid(char* s) {
    int count = 0;
    char* Cur = s;
    while (*Cur)
    {
        count++;
        Cur++;
    };
    if(count%2){
        return false;
    }
    printf("%d\n",count);
    int mid = count/2;
    for(int i = 0;i<mid;i++){
        if(s[i]!=s[mid+i]){
            printf("%c\n",s[i]);
            printf("%c\n",s[mid+i]);
            return false;
        }
    }
    return true;
}
int main(){
    char arr[10] = "{}";
    if(isValid(arr)){
        printf("true!\n");
    }
    else
        printf("false\n");
}