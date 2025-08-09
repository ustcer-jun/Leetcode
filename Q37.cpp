#include<iostream>
#include<assert.h>
#include<string.h>
#include<ctype.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        int This = 0;
        int target =0;
        while(target<size){
            char ch = s[target];
            This = 0;
            int flag = 0;
            while(This < size){
                if(s[This] == ch){
                    flag = 1;
                    break;
                }
                This++;
            }
            if(flag == 0){
                return target;
            }
            target++;
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};
        int size = s.size();
        for(auto ch : s){
            count[ch - 'a']++;
        };
        for(int i = 0;i<size;i++){
            if(count[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;

    }
};

int main(){
    Solution s;
    string s1("aabb");
    cout<< s.firstUniqChar(s1)<<endl;
    
}