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
    pair<int, int> longestPath(TreeNode* root)
    {
        if (!root)
            return {0, 0};

        int incr = 1;
        int decr = 1;
        int rootVal = root->val;
        if (root->left)
        {
            auto lPath = longestPath(root->left);
            int lVal = root->left->val;
            if (lVal == rootVal + 1)
                incr = max(incr, lPath.first + 1);
            if (lVal == rootVal - 1)
                decr = max(decr, lPath.second + 1);
        }
        if (root->right)
        {
            auto rPath = longestPath(root->right);
            int rVal = root->right->val;
            if (rVal == rootVal + 1)
                incr = max(incr, rPath.first + 1);
            if (rVal == rootVal - 1)
                decr = max(decr, rPath.second + 1);
        }

        res = max(res, decr + incr - 1);
        return {incr, decr};
    }

    int longestConsecutive(TreeNode* root) {
        res = 0;
        longestPath(root);
        return res;
    }
};
