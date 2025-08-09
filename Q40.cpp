#include <iostream>
using namespace std;
#include <stdlib.h> 
// void reverse(char* str){
//     if(!str){
//         printf("void string!\n");
//         return;
//     }
//     int left = 0;
//     int right = strlen(str) - 1;
//     while(left<right){
//         char tmp = str[left];
//         str[left] = str[right];
//         str[right] = tmp;
//         left++;
//         right--;
//     };
// }


// char *Addstrings(char *num1, char *num2)
// {
//     int end1 = strlen(num1) - 1;
//     int end2 = strlen(num2) - 1;
//     int next = 0;
//     int max = sizeof(num1) > sizeof(num2) ? sizeof(num1) : sizeof(num2);
//     char* str = (char*)malloc(sizeof(char)* (max + 1));
//     int i = 0;
//     while (end1 >= 0 || end2 >= 0)
//     {
//         int val1 = 0;
//         int val2 = 0;
//         int sum = 0;
//         if (end1 >= 0)
//         {
//             val1 = num1[end1] - '0';
//         }
//         if (end2 >= 0)
//         {
//             val2 = num2[end2] - '0';
//         }
//         sum = val1 + val2 + next;
//         if (sum >= 10)
//         {
//             sum -= 10;
//             next = 1;
//         }
//         else{
//             next = 0;
//         }
//         str[i++] = sum+'0';
//         end1--;
//         end2--;
//     }
//     if(next != 0){
//         str[i++] = next+'0';
//     }
//     str[i] = '\0';
//     reverse(str);
//     return str;
// }

// char *multiply(char *num1, char *num2)
// {
//     int size1 = strlen(num1)+1;
//     int size2 = strlen(num2)+1;
//     char* res = (char*)calloc((size1+size2+1),sizeof(char));
//     char* str = (char*)calloc(size2,sizeof(char));
//     str[0] = '0'; res[0]= '0';
//     while (strcmp(str, num2) != 0)
//     {
//         char* tmp = Addstrings(res,num1);
//         free(res);
//         res = tmp;
//         char one[]="1";
//         str = Addstrings(str,one);
//     }
//     return res;
// }
// char *multiply(const char *num1, const char *num2) {
//     if (num1[0] == '0' || num2[0] == '0') {
//         char *zero = malloc(2);
//         strcpy(zero, "0");
//         return zero;
//     }

//     int len1 = strlen(num1);
//     int len2 = strlen(num2);
//     int *temp = calloc(len1 + len2, sizeof(int)); // 存每一位乘积

//     // 从最低位开始竖式相乘
//     for (int i = len1 - 1; i >= 0; i--) {
//         if (!isdigit(num1[i])) continue; // 忽略非数字
//         for (int j = len2 - 1; j >= 0; j--) {
//             if (!isdigit(num2[j])) continue;
//             int mul = (num1[i] - '0') * (num2[j] - '0');
//             int sum = mul + temp[i + j + 1];
//             temp[i + j + 1] = sum % 10;
//             temp[i + j] += sum / 10;
//         }
//     }

//     // 转成字符串
//     int start = 0;
//     while (start < len1 + len2 && temp[start] == 0) start++; // 跳过前导0

//     char *res = malloc(len1 + len2 - start + 1);
//     int k = 0;
//     for (int i = start; i < len1 + len2; i++) {
//         res[k++] = temp[i] + '0';
//     }
//     res[k] = '\0';

//     free(temp);
//     return res;
// }

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        int* mul = new int[size1+size2](); 
        int end1 = size1 -1;
        int end2 = size2 -1;
        for(int i = end1;i >= 0; i--){
            int val1 = num1[i]- '0';
            for(int j = end2;j >= 0;j--){
                int val2 = num2[j] - '0';
                int sum = mul[i+j+1] + val1*val2;
                mul[i+j+1] = sum%10;
                mul[i+j] += sum/10;
            }
        }
        // 转化为字符串
        int start = 0;
        while (start < size1 + size2 - 1 && mul[start] == 0) start++;
        string res;
        for (int i = start; i < size1 + size2; i++){
            res.push_back(mul[i] + '0');
        };
        delete[] mul;
        mul = nullptr;
        return res;
    }
};


int main()
{
    // char num1[] = "9456";
    // char num2[] = "789";
    Solution s1;
    // char num1[] = "123456789";
    // char num2[] = "987654321";
    string S1("123456789");
    // cout << S1.size() << endl;
    string S2("987654321");
    // cout << S2.size() << endl;
    // char *sum = Addstrings(num1, num2);
    // char *mul = multiply(num1, num2);
    string res = s1.multiply(S1,S2);
    cout << res << endl;
}