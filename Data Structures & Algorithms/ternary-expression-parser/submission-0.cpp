struct Node
{
    char c{};
    Node* left{nullptr};
    Node* right{nullptr};

    Node(char& cc)
        : c(cc)
    {}
};

class Solution {
private:
    int idx{};

    Node* buildTree(string& exp)
    {
        Node* root = new Node(exp[idx]);
        if (idx == exp.size() - 1)
            return root;

        idx++;
        if (exp[idx] == '?')
        {
            idx++;
            root->left = buildTree(exp);
            idx++;
            root->right = buildTree(exp);
        }
        return root;
    }

public:
    string parseTernary(string expression) {
        Node* root = buildTree(expression);
        while (root->left && root->right)
        {
            if (root->c == 'T')
                root = root->left;
            else
                root = root->right;
        }
        return string(1, root->c);
    }
};
