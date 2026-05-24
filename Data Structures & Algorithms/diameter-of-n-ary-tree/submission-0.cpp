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
private:
    int res{};

    int dfs(Node* node)
    {
        if (node->children.size() == 0)
            return 0;

        int maxHeight1 = 0;
        int maxHeight2 = 0;
        for (Node* c : node->children)
        {
            int parentHeight = dfs(c) + 1;
            if (parentHeight > maxHeight1)
            {
                maxHeight2 = maxHeight1;
                maxHeight1 = parentHeight;
            }
            else if (parentHeight > maxHeight2)
            {
                maxHeight2 = parentHeight;
            }
            res = max(res, maxHeight1 + maxHeight2);
        }
        return maxHeight1;

    }
public:
    int diameter(Node* root) {
        dfs(root);
        return res;
    }
};
