#include<iostream>
#include<vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = accumulate(gas.begin() , gas.end(),0);
        int sum_cost = accumulate(cost.begin() , cost.end(),0);
        for (int i = 0; i < gas.size(); i ++)
        {
            gas[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < gas.size(); i ++)
        {
            cost[i] = cost[i] - gas[i];
        }
        if (sum_gas < sum_cost) return -1;
        else
        {
            vector<int>::iterator max = max_element(begin(cost), end(cost));
            int max_pos = distance(cost.begin(), max);
            if (max_pos == cost.size() - 1) return 0;
            else
            {
                return max_pos + 1;
            }
            
        }
        
    }
};

int main()
{
    Solution s;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int ans = s.canCompleteCircuit(gas,cost);

}