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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<pair<TreeNode*, int>> q;
        int minCol = 0;
        int maxCol = 0;
        unordered_map<int, vector<int>> col2val;
        q.push({root, 0});
        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                auto [cur, col] = q.front();
                q.pop();
                if (!cur)
                    continue;

                minCol = min(minCol, col);
                maxCol = max(maxCol, col);
                col2val[col].push_back(cur->val);
                if (cur->left)
                    q.push({cur->left, col - 1});
                if (cur->right)
                    q.push({cur->right, col + 1});
            }
        }

        vector<vector<int>> res;
        for (int c = minCol; c <= maxCol; c++)
        {
            res.push_back(col2val[c]);
        }
        return res;
    }
};