#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length() + 1;
        vector<int> dict(len,0);
        dict[0] = 1;
        for (int i = 1; i < len ; i ++ )
        {
            
            for (auto word : wordDict)
            {
                if (i >= word.length()){
                    int comp = s.compare(i-word.length() ,word.length() ,word);
                    if (comp == 0 && dict[i-word.length()] == 1){
                        dict[i] = 1;
                    }
                }
            }
        }
        return dict[len - 1];
    }
};

int main(){
    Solution s;
    vector<string> wordDict = {"apple", "pen"};
    string str = "applepenapple";
    bool i = s.wordBreak(str, wordDict);
    cout<<i<<endl;
}