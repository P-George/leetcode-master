#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * after = slow->next;
        slow->next = nullptr;
        ListNode * tmp = nullptr;
        ListNode * pre = nullptr;
        while (after)
        {
            tmp = after->next;
            after->next = pre;
            pre = after;
            after = tmp;
        }
        ListNode listf(0);
        listf.next = head;
        while (head && pre)
        {
            tmp = head;
            head = head->next;
            tmp->next = pre;
            pre = pre->next;
            tmp = tmp->next;
            tmp->next = head;
        }
        head = listf.next;
    }
};
ListNode * create(int test[],int n){
    ListNode *head ,*p , *tail;
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
    int test[] = {5,89,7,3,8};
    int n = sizeof(test)/sizeof(test[0]);
    ListNode *head = create(test,n);
    s.reorderList(head);
    output_list(head);
    return 0;
}