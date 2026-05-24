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
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (root->left && root->left->val == root->val + 1)
            left++;

        if (root->right && root->right->val == root->val + 1)
            right++;

        int maxPath = max({left, right, 1});
        res = max(res, maxPath);
        return maxPath;
    }

    int longestConsecutive(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};
