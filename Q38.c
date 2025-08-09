
#include<iostream>
#include<assert.h>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

void reverse(char* str) {
    assert(str);
    int num = strlen(str);
    int left = 0;
    int right = num - 1;
    while (right > left) {
        char ch = str[left];
        str[left] = str[right];
        str[right] = ch;
        right--;
        left++;
    }
}

char* get_alpha(const char* str) {
    char* str_copy = (char*)malloc(200000 * sizeof(char));
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || 
            (str[i] >= 'A' && str[i] <= 'Z') || 
            (str[i] >= 'a' && str[i] <= 'z')) {
            char ch = str[i];
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32; // 转小写
            }
            str_copy[j++] = ch;
        }
    }
    str_copy[j] = '\0'; // ✅ 记得添加终止符
    return str_copy;
}

bool issame(const char* str1, const char* str2) {
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    if (size1 != size2) return false;
    for (int i = 0; i < size1; i++) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

bool isPalindrome(char* s) {
    char* s1 = get_alpha(s);
    char* s2 = get_alpha(s);
    reverse(s2);
    bool result = issame(s1, s2);
    free(s1); // ✅ 别忘了释放内存
    free(s2);
    return result;
}

class Solution {
public:
    void lower2upper(string& s){
        for(auto& ch : s){
            if(ch >= 'a' && ch <= 'z'){
                ch -= 32;
            }
        }
    };
    bool isalpha_number(char ch){
        if((ch>='0' && ch<='9')||(ch>='A' && ch<='Z')){
            return true;
        }
        else{
            return false;
        }
    };

    bool isPalindrome(string s){
        lower2upper(s);
        int begin = 0;
        int end = s.size()-1;
        while (begin < end)
        {
            while(begin < end && !isalpha_number(s[begin])){
                begin++;
            }
            while(begin < end && !isalpha_number(s[end])){
                end--;
            }
            if(s[end]!=s[begin]){
                return false;
            }
            else{
                begin++;
                end--;
            }
        }
        return true;       
    }
};