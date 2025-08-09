#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <algorithm>  // std::reverse
// void reverse(char* str) {
//     assert(str);
//     int num = strlen(str);
//     int left = 0;
//     int right = num - 1;
//     while (right > left) {
//         char ch = str[left];
//         str[left] = str[right];
//         str[right] = ch;
//         right--;
//         left++;
//     }
// }
// char* addStrings(char* num1, char* num2) {
//     assert(num1 && num2);
//     int len1 = strlen(num1);
//     int len2 = strlen(num2);
//     int max = len1 > len2 ? len1 : len2;
//     char* str = (char*)realloc(0,sizeof(char)*(max+1));
//     int next = 0;int ret =0;int i = 0;
//     int end1 = len1 -1;int end2 = len2 -1;
//     while (end1 >= 0  || end2 >= 0)
//     {
//         int val1 = 0;
//         int val2 = 0;
//         if(end1 >= 0){
//             val1 = num1[end1] -'0';
//         }
//         if(end2 >= 0){
//             val2 = num2[end2] -'0';
//         }
//         ret = val1 + val2 + next;
//         if(ret>=10){
//             ret -= 10;
//             next = 1;
//         }
//         else{
//             next = 0;
//         }
//         str[i++] = ret+'0';
//         end1--;
//         end2--;
//     }
//     if(next!=0){
//         str[i] = next+'0';
//     };
//     reverse(str);
//     return str;
// };
// int main(){
//     char num1[] = "9831";
//     char num2[] = "456";
//     char* ps = addStrings(num1,num2);
//     // char* str = (char*)realloc(0,sizeof(char)*(5+1));
//     printf("%s\n",ps);
// }


class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size()-1;
        int end2 = num2.size()-1;
        int next = 0;  int ret = 0;
        string s1;
        while (end1>=0 || end2>=0)
        {
            int val1 = 0;int val2 = 0;
            if(end1 >= 0){
                val1 = num1[end1]-'0';
            }
            if(end2 >= 0){
                val2 = num2[end2]-'0';
            }
            ret = val1 + val2 + next;
            if(ret >= 10){
                ret -= 10;
                next = 1;
            }
            else{
                next = 0;
            }
            s1 += (ret+'0');
            end1--;
            end2--;
        }
        if(next!=0){
            s1+= (next + '0');
        }
        std::reverse(s1.begin(), s1.end());
        return s1;
    }
};


int main(){
    Solution sol;
    char num1[] = "9831";
    char num2[] = "456";
    string ps = sol.addStrings(num1,num2);
    // char* str = (char*)realloc(0,sizeof(char)*(5+1));
    cout << ps << endl;
}
