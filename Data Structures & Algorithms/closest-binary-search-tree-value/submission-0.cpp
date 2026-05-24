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
    int closestValue(TreeNode* root, double target) {
        int val = 0;
        int closest = root->val;

        while (root)
        {
            val = root->val;
            if (abs(val - target) == abs(closest - target))
                closest = min(val, closest);
            else if (abs(val - target) < abs(closest - target))
                closest = val;

            if (target < val)
                root = root->left;
            else
                root = root->right;
        }
        return closest;
    }
};
