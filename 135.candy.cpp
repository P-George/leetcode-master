#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int totanum = 0;
        vector<int> cop_ratings(ratings);
        int score[7] = {1};
        for(int i = 1; i <7; i++)
        {
            score[i] = 1;
        }
        sort(cop_ratings.begin(),cop_ratings.end());
        cop_ratings.erase(unique(cop_ratings.begin(), cop_ratings.end()), cop_ratings.end());
        //vector<int> score(ratings.size(),1);
        for (auto digital:cop_ratings)
        {
            //for (int i = 0;i < score.size();i++)
            for (int i = 0;i < 7;i++)
            {
                if (ratings[i] == digital)
                {
                    if (i == 0)
                    {
                        if (ratings[i] > ratings[i+1])
                        {
                            score[i]++;
                        }
                    }
                    else if (i == 6)
                    //else if (i == score.size()-1 && ratings[i] > ratings[i-1])
                    {
                        if(ratings[i] > ratings[i-1])
                        {
                            score[i] = score[i-1] + 1;
                        }
                    }
                    else
                    {
                        if (ratings[i] > ratings[i-1])
                        {
                            score[i] = score[i-1] + 1;
                        }
                        if (ratings[i] > ratings[i+1])
                        {
                            if (score[i] < score[i+1] + 1)
                            {
                                score[i] = score[i+1] + 1;
                            }
                        }
                    }
                    
                }
            }
        }
        for (int i = 0; i < ratings.size();i++)
        {
            totanum += score[i];
        }
        return totanum;
    }
};

int main()
{
    Solution s;
    vector<int> rate = {1,6,10,8,7,3,2};
    int a = s.candy(rate);
    return 0;
}