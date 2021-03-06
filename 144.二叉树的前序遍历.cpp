/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> pre_ans;
       stack<TreeNode *> s;
       if (!root) return pre_ans;
       TreeNode * cur = root;
       while (!s.empty()||cur)
       {
           while (cur)
           {
               s.push(cur);
               pre_ans.push_back(cur->val);
               cur = cur->left;
           }
           cur = s.top();
           s.pop();
           cur = cur->right;

       }
    return pre_ans;
       
    }
};
// @lc code=end

