#include<iostream>
#include<vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<string> cur;
        dfs(s,cur);
        return cur.size();
    }
 
    bool isPalindrome(string s){
        return s==string(s.rbegin(),s.rend());
    }
 
    void dfs(string s,vector<string> &cur){
        if (s==""){
            return;
        }
 
        for (int i = s.length(); i >= 1; i--) {
            string sub=s.substr(0,i);
            if (isPalindrome(sub)){
                cur.push_back(sub);
                dfs(s.substr(i,s.length()-i),cur);
            }
        }
 
    }
 
};

int main()
{
    Solution s;
    string string1 = "aab";
    int ans = s.minCut(string1);

}