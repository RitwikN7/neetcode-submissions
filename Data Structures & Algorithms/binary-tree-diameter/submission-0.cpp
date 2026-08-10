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
    int res{};

    int dfs(TreeNode* node)
    {
        if (!node)
            return 0;

        int r = dfs(node->right);
        int l = dfs(node->left);

        res = max(res, l + r);
        return 1 + max(r, l);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
