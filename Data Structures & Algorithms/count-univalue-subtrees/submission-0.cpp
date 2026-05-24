/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int res;
public:
    pair<int, int> dfs(TreeNode* root)
    {
        if (!root)
            return {-1, 1};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool isUniVal = (left.first == -1 || root->val == left.first)
                        && (right.first == -1 || root->val == right.first)
                        && (left.second && right.second);
        if (isUniVal)
            res++;
        return {root->val, isUniVal};
    }

    int countUnivalSubtrees(TreeNode* root) {
        res = 0;

        dfs(root);
        return res;
    }
};
