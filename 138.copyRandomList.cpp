#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        while (cur)
        {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            copy->random = cur->random;
            cur->next = copy;
            cur = copy->next;
        }
        cur = head;
        cur = cur->next;
        while (cur->next)
        {
            if (cur->random){
                cur->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node* cur1 = head;
        Node* head_next = head->next;
        cur = cur1->next;
        while(cur->next)
        {
            cur1->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            cur1 = cur1->next;
        }
        cur1->next = nullptr;
        return head_next;
    }

};

Node* create(int array1[5][2],int len)
{
    Node* head = new Node(0);
    Node* node_new = head;
    vector<Node*> obj;
    for (int i = 0;i < len;i ++)
    {
        node_new->next = new Node(array1[i][0]);
        node_new = node_new->next;
        obj.push_back(node_new);
    }
    node_new = head->next;
    for (int i = 0;i < len ;i ++)
    {
        if (array1[i][1] == 100)
        {
            node_new->random = nullptr;
        }
        else
        {
            node_new->random = obj[array1[i][1]];
        }
        node_new = node_new->next;      
    }
    return head->next;
}

int main()
{
    int array1[5][2] = {{7,100},{13,0},{11,4},{10,2},{1,0}};
    Node* head = create(array1,5);
    Solution s;
    head = s.copyRandomList(head);
}