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
    vector<vector<int>> res;
public:
    int dfs(TreeNode* root)
    {
        if (!root)
            return -1;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        int height = max(leftHeight, rightHeight) + 1;

        if (res.size() == height)
            res.push_back({});

        res[height].push_back(root->val);
        return height;   
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        res.clear();
        dfs(root);
        return res;
    }
};
