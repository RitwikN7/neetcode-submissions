class Solution {
private:
    vector<vector<int>> adj;

    int dfs(int i, vector<int>& vis)
    {
        if (vis[i] != 0)
            return vis[i];

        vis[i] = -1;
        int maxLength = 1;
        for (const auto& nei : adj[i])
        {
            int length = dfs(nei, vis);
            if (length == -1)
                return -1;

            maxLength = max(maxLength, length + 1);
        }
        return vis[i] = maxLength;
    }

public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        adj.resize(n + 1);
        for (const auto& e : relations)
            adj[e[0]].push_back(e[1]);

        int res = -1;
        vector<int> visited(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int length = dfs(i, visited);
            if (length == -1)
                return -1;

            res = max(res, length);
        }
        return res;
    }
};
