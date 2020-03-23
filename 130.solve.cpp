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
    void solve(vector<vector<char>>& board) {
        int len = board.size();
        int bor = board[0].size();
        vector<vector<bool>> judge = vector<vector<bool>>(len,vector<bool>(bor,true));
        for (int i=0;i<len;i++)
        { 
            if (board[i][0] == 'O')
            {
                dft(board,len,bor,i,0,judge);
            }
            if (board[i][bor-1] == 'O')
            {
                dft(board,len,bor,i,bor-1,judge);
            }
        }
        for (int j=0;j<bor;j++)
        {
            if (board[0][j] == 'O')
            {
                dft(board,len,bor,0,j,judge);
            }                
            if (board[len-1][j] == 'O') 
            {
                dft(board,len,bor,len-1,j,judge);
            }     
        }
        for (int i=0;i<len;i++)
        {
            for (int j=0;j<bor;j++)
            {
                if (board[i][j] == 'O' && judge[i][j])
                {
                    board[i][j] == 'X';
                }
            }
        }
    }
    void dft(vector<vector<char>>& board,int len,int bor,int i,int j,vector<vector<bool>>& judge)
    {
        if (i<len && j<bor && i>=0 && j>=0)
        {
            if (board[i][j] == 'O' && judge[i][j])
            {
                judge[i][j] = false;
                dft(board,len,bor,i-1,j,judge);
                dft(board,len,bor,i,j-1,judge);
                dft(board,len,bor,i+1,j,judge);
                dft(board,len,bor,i,j-1,judge);
            }
            else
            {
                return;
            }
            
        }
        else{
            return;
        }
    }
};
int main()
{
    Solution s;
    vector<vector<char>> string1 = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(string1);
    int len = string1.size();
    int bor = string1[0].size();
    for (int i=0;i<len;i++)
        {
            for (int j=0;j<bor;j++)
            {
                char c = string1[i][j];
            }
            printf("/n");
        }

}