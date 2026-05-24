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
    double res;
public:
    pair<int, int> dfs(TreeNode* root)
    {
        if (!root)
            return {0, 0};

        auto lPair = dfs(root->left);
        auto rPair = dfs(root->right);
        int count = lPair.second + rPair.second + 1;
        int sum = lPair.first + rPair.first + root->val;
        double avg = sum * 1.0 / count;
        res = max(res, avg);
        return {sum, count};
    }

    double maximumAverageSubtree(TreeNode* root) {
        res = 0.0;
        dfs(root);
        return res;
    }
};
