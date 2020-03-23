/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode listf(0);
        listf.next = head;
        auto p = listf.next;
        int length = 0;
        while (p){
            p = p->next;
            length++;
        }
        for(int i = 1;i < length;i = i * 2)
        {
            auto cur = listf.next;
            auto tail = &listf;
            while(cur){
                auto left = cur;
                auto right = cut(left,i);
                cur = cut(right,i);
                tail->next = merge(left,right);
                while (tail->next){
                    tail = tail->next;
                }
            }
        }
        return listf.next;
    }
    ListNode *cut(ListNode *head ,int step){
        auto p = head;
        while(p && --step > 0)
        {
            p = p->next;
        }
        if(!p)
            return nullptr;
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    ListNode *merge(ListNode *left ,ListNode *right){
        ListNode dummy(0);
        auto p = &dummy;
        while(left && right){
            if(left->val <= right->val){
                p->next = left;
                left = left->next;
            }
            else{
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left:right;
        return dummy.next;
    }
};

ListNode * create(int test[]){
    ListNode *head ,*p , *tail;
    int n = sizeof(test);
    head = (ListNode*) malloc(sizeof(ListNode));
    tail = head;
    for (int i = 0;i < n;i++){
        p = (ListNode*) malloc(sizeof(ListNode));
        p->val = test[i];
        tail->next = p;
        tail = p;
        p = p->next;
    }
    tail->next = NULL;
    return head->next;
}

void output_list(ListNode* head){
    while (head)
    {
        cout << head->val;
        head = head->next;
    }
    cout<<endl;
}

int main() {
    // insert code here...
    Solution s;
    int test[] = {5,89,7,3};
    ListNode *head = create(test);
    ListNode *fin_list = s.sortList(head);
    output_list(fin_list);
    return 0;
}
// @lc code=end

