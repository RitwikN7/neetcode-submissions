class Solution {
public:
    void dfs(int left, int right, int n, vector<string> &res, string stack)
    {
        if (stack.size() == n * 2)
        {
            res.push_back(stack);
            return;
        }

        if (left < n)
            dfs(left + 1, right, n, res, stack + "(");

        if (right < left)
            dfs(left, right + 1, n, res, stack + ")");

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, n, res, "");
        return res;
    }
};
