/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
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
                string strjudge = s.substr(i,j - i);
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
// @lc code=end

