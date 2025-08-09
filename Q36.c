#include<iostream>
#include<assert.h>
#include<string.h>
#include<ctype.h>
using namespace std;
char* reverse_str(char* pc){
    assert(pc);
    int len = strlen(pc);
    int left = 0;int right = len-1;
    while(left<right){
        if(!isalpha((unsigned char)pc[left]) && isalpha((unsigned char)pc[right])){
            left++;
        }   
        else if(!isalpha((unsigned char)pc[right]) && isalpha((unsigned char)pc[left])){
            right--;
        }
        else if(!isalpha((unsigned char)pc[right]) && !isalpha((unsigned char)pc[left])){
            right--;
            left++;
        }
        else{
            char tmp = pc[left];
            pc[left] = pc[right];
            pc[right] = tmp;
            right--;
            left++;
        }
    }
    return pc;
}
int main(){
    char str[] = {"a-bC-dEf-ghIj"};
    char str1[] ={"7_28]"};
    printf("%s\n",str1);
    reverse_str(str1);
    printf("%s\n",str1);
}

char* reverseOnlyLetters(char* pc) {
    assert(pc);
    int left = 0, right = strlen(pc) - 1;
 
    while (left < right) {
        if (!isalpha((unsigned char)pc[left])) {
            left++;
        } else if (!isalpha((unsigned char)pc[right])) {
            right--;
        } else { // 两边都是字母
            char tmp = pc[left];
            pc[left++] = pc[right];
            pc[right--] = tmp;
        }
    }
    return pc;
}
