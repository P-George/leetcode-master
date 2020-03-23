#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast->val == slow->val)
            {
                break;
            }
        }
        if (!fast->next || !fast->next->next)
        {
            return nullptr;
        }
        while (true)
        {
            if (head->val == fast->val)
            {
                return head;
            }
            else{
                head = head->next;
                fast = fast->next;
            }
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
    tail->next = head->next->next;
    return head->next;
}

int main() {
    Solution s;
    int test[] = {5,89,7,3};
    ListNode *head = create(test);
    ListNode *fin_list = s.detectCycle(head);
    return 0;
}