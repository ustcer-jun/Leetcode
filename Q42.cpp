#include<iostream>
using namespace std;

// class MinStack {
// public:
//     MinStack() {
        
//     }
//     void push(int val) {
//         _st.push(val);
//         if(_minst.empty() ||_minst.top()>=val ){
//             _minst.push(val);
//         }
//     }
    
//     void pop() {
//         if(!_st.empty()){
//             if(_st.top() == _minst.top()){
//                 _minst.pop();
//             }
//             _st.pop();
//         }
//     }
    
//     int top() {
//         return _st.top();
//     }
    
//     int getMin() {
//         return _minst.top();
//     }
// private:
//     stack<int> _st;
//     stack<int> _minst;
// };

// class MinStack {
// public:
//     MinStack()
//     :_min_val(0)
//     ,st_diff()
//     {}
//     void push(int val) {
//         if(st_diff.empty()){
//             _min_val = val;
//             st_diff.push(0);
//         }
//         if(val<_min_val){
//             _min_val = val;
//         }
//         st_diff.push(val-_min_val);
//     }
    
//     void pop() {
//         if(st_diff.top() < 0){
//             _min_val = _min_val - st_diff.top();
//         }
//         st_diff.pop();
//     }
    
//     int top() {
//         if(st_diff.top() > 0){
//             return _min_val + st_diff.top();
//         }
//         else{
//             return _min_val;
//         }
//     }
    
//     int getMin() {
//         return _min_val;
//     }
// private:
//     int _min_val;
//     stack<int> st_diff;
// };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        size_t j = 0;
        for(size_t i = 0;i<pushV.size();++i){
            st.push(pushV[i]);
            while(!st.empty() && st.top() == popV[j] ){
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }

    stack<int> st;
};



int main(){
    Solution s1;
    vector<int> push1 = {1};
    vector<int> pop1 = {1};
    if(s1.IsPopOrder(push1,pop1)){
        cout<<"True!"<<endl;
    }
    else{
        cout<<"Wrong!"<<endl;
    }
}

// int main(){
//     MinStack ms1;
//     ms1.push(0);
//     ms1.push(1);
//     ms1.push(0);
//     cout<< "Min value = "<<ms1.getMin()<<endl;
//     ms1.pop();
//     cout<< "Min value = "<<ms1.getMin()<<endl;
//     ms1.pop();
//     cout<< "Min value = "<<ms1.getMin()<<endl;
//     ms1.pop();
//     ms1.push(-2);
//     ms1.push(-1);
//     ms1.push(-2);
//     cout<< "Min value = "<<ms1.getMin()<<endl;
//     ms1.pop();
//     cout<< "Top value = "<<ms1.top()<<endl;
//     cout<< "Min value = "<<ms1.getMin()<<endl;
//     ms1.pop();
//     cout<< "Min value = "<<ms1.getMin()<<endl;
//     ms1.pop();
// }