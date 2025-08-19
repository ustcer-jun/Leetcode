#include<iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& str: tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/" ){
                int _right = st.top();
                st.pop();
                int _left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(_left+_right);
                    break;
                case '-':
                    st.push(_left - _right);
                    break;
                case '*':
                    st.push(_left * _right);
                    break;
                case '/':
                    st.push(_left / _right);
                    break;
                }
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    };
};

// int main(){
//     Solution s1;
//     vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//     cout<< s1.evalRPN(tokens);

// }

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        stack<int> st2;
        stack<int> st1;
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop(){
        int _top = 0; 
        if(st2.empty()){
            size_t sz = st1.size();
            while (sz > 1)
            {
                int val = st1.top();
                st2.push(val);
                st1.pop();
                --sz;
            }
            _top = st1.top();
            st1.pop();
        }
        else{
            _top = st2.top(); 
            st2.pop();
        }
        return _top;
    }
    int peek() {
        int _top = 0; 
        if(st2.empty()){
            size_t sz = st1.size();
            while (sz > 0)
            {
                int val = st1.top();
                st2.push(val);
                st1.pop();
                --sz;
            }
        }
        return st2.top();
    }
    
    bool empty() {
       return st1.empty() && st2.empty() ;
    }
};

int main(){
    MyQueue q1;
    q1.push(1);
    q1.push(2);
    cout<< q1.peek()<<endl;
    q1.pop();
    if(q1.empty()){
        cout<<"True!"<<endl;
    }
    else{
        cout<<"False!"<<endl;
    }
}