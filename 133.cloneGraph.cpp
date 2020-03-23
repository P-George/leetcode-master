#include<iostream>
#include<vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mapnode;
        queue<Node *> allnodes;
        allnodes.push(node);
        while (!allnodes.empty())
        {
            Node* nodenew = allnodes.front();
            allnodes.pop();
            mapnode[nodenew] = new Node(nodenew->val);
            for (auto nodes:nodenew->neighbors)
            {
                if (mapnode.find(nodes) == mapnode.end())
                {
                    allnodes.push(nodes);
                }
            }
        }
        map<Node *,Node *>::iterator iter;
		for( iter = mapnode.begin(); iter != mapnode.end(); ++iter )
        {
            for (Node *neighborsNode : iter->first->neighbors)
            {
                iter->second->neighbors.push_back(mapnode[neighborsNode]);
            }
        }
        return mapnode[node];
    }
};

int main()
{
    Solution s;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    Node* ans = s.cloneGraph(node1);
    return 0;
}
// @lc code=end

