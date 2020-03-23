/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode listf(0);
        while(head){
            auto sorted = &listf;
            auto insNode = sorted->next;
            while (insNode && (insNode->val < head->val))
            {
                insNode = insNode->next;
                sorted = sorted->next;
            }
            sorted->next = head;
            head = head->next;
            sorted->next->next = insNode;
        }
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
    ListNode *fin_list = s.insertionSortList(head);
    output_list(fin_list);
    return 0;
}
// @lc code=end

