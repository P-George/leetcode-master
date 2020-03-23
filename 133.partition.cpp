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
    vector<vector<string>> partition(string s) {
        vector<int> judge = vector(s.length() + 1,0);
        unordered_map <int,vector<vector<string>>> ump;
        for (int i = 0;i < s.length(); i++)
        {
            ump[i] = vector<vector<string>> ();
        }
        judge[0] = 1;
        for (int i = 0;i < s.length(); i++)
        {
            for (int j = i + 1;j < s.length() + 1;j++)
            {
                string strjudge = s.substr(i,j);
                if (is_palindrome(strjudge))
                {
                    vector<string> vec = vector<string>();
                    if (i == 0)
                    {
                        vec.push_back(strjudge);
                        ump[j-1].push_back(vec);
                    }
                    else
                    {
                        for (auto vs:ump[i-1])
                        {
                            vec = vector(vs);
                            vec.push_back(strjudge);
                            ump[j-1].push_back(vec);
                        }
                    }
                    
                }
            }
        }
        return ump[s.length() - 1];
    }
    bool is_palindrome(const string str) {
        int length = str.length();
        for (int i = 0; i < length / 2; ++i)
            if (str[i] != str[length - i - 1])
                return false;
        return true;
    };

};

int main()
{
    Solution s;
    string string1 = "aab";
    vector<vector<string>> ans = s.partition(string1);

}