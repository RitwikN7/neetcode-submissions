/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int sum = 0;
        for (const auto& node : tree)
        {
            sum += node->val;
            for (const auto& c : node->children)
                sum -= c->val;
        }
        for (const auto& node : tree)
        {
            if (node->val == sum)
                return node;
        }
        return nullptr;
    }
};
