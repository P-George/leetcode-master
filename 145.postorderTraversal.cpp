/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
#include <iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pos_que;
        stack<TreeNode*> s;
        TreeNode * tmp;
        if(root == NULL) return pos_que;
        s.push(root);
        while (!s.empty)
        {
            tmp = s.top;
            if (!tmp->left && !tmp->right){
                pos_que.push_back(tmp->val);
                s.pop;
            }
            else{
                if (tmp->right){
                    s.push(tmp->right);
                    tmp->right = NULL;
                }
                if (tmp->left){
                    s.push(tmp->left);
                    tmp->left = NULL;
                } 
            }
        }  
        return pos_que;
    }
};
// @lc code=end

