#include <iostream>
using namespace std;

// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         vector<int> count_arr(32);
//         size_t i = 0;
//         for (auto num : nums)
//         {
//             while (num)
//             {
//                 if (num & 1)
//                 {
//                     count_arr[i]++; // 统计1出现的次数
//                 }
//                 num >>= 1;
//             }
//             i++;
//         }
//         size_t ret = 0;
//         int j = 0;
//         for (auto count : count_arr)  
//         {
//             if (count % 3 != 0)
//             { // 模3不为0，则找到对应元素的二进制位为1.
//                 ret += (1 << j);
//             }
//             j++;
//         } 
//         return ret;
//     }
// };

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         int res = 0;
//         for(auto num:nums){
//             res ^= num;
//         }
//         size_t tar =1;
//         for(size_t i = 0; i < 32; i++){
//             if((res & 1) == 0 ){
//                 res>>=1;
//             }
//             else{
//                 tar <<= i;
//                 break;
//             }
//         }
//         vector<int> n1(nums.size());
//         vector<int> n2(nums.size());
//         for(auto num:nums){
//             if(num & tar){
//                 n1.push_back(num);
//             }
//             else{
//                 n2.push_back(num);
//             }
//         }
//         int ret1 = 0; int ret2 = 0;
//         for(auto val1 : n1){
//             ret1^= val1;
//         }
//         for(auto val2 :n2){
//             ret2 ^= val2;
//         }
//         vector<int> ret = {ret1,ret2};
//         return ret;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> arr_arr(numRows);
//         //  size_t index =0;
//         for(size_t j =0; j<numRows; j++ ){
//             if(j == 0){
//                 arr_arr[j].push_back(1);  
//             }
//             else{
//                 for(size_t i = 0; i<=j;i++){
//                     if(i == 0){
//                         arr_arr[j].push_back(1);
//                     }
//                     else if(i == j){
//                         arr_arr[j].push_back(1);
//                     }
//                     else{
//                         arr_arr[j].push_back((arr_arr[j-1])[i-1]+(arr_arr[j-1])[i]);
//                     }

//                 }
//             }

//         }
//         return arr_arr;
//     }
// };


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr_arr;
        arr_arr.resize(numRows);
        for(size_t i = 0; i<numRows; i++){
            arr_arr[i].resize(i+1);
            arr_arr[i][0] = 1;
            arr_arr[i][i] = 1;
        }
        for(size_t i = 0; i<numRows; i++){
            for(size_t j = 0; j<arr_arr[i].size(); j++){
                if(arr_arr[i][j] != 1){
                    arr_arr[i][j] = arr_arr[i-1][j]+arr_arr[i-1][j-1];
                }
            }
        }
        return arr_arr;
    }
};


int main(){
    // vector<int> v1 = {1,2,1,3,2,5};
    Solution s1;
    // vector<int> v2 = s1.singleNumber(v1);
    // for(auto num:v2){
    //     cout << num<<" ";
    // }
    vector<vector<int>> arr_arr = s1.generate(5);
    for(auto arr: arr_arr){
        cout<<"[";
        for(auto val : arr){
            cout<<val<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}