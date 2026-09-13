class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int>> adj(n);
        for (const auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> seen;
        for (int i = 0; i < n; i++)
        {
            if (seen.count(i))
                continue;

            res++;
            dfs(i, adj, seen);
        }

        return res;
    }

    void dfs(int i, vector<vector<int>>& adj, unordered_set<int>& seen)
    {
        if (seen.count(i))
            return;

        seen.insert(i);
        for (auto& n : adj[i])
        {
            dfs(n, adj, seen);
        }
    }
};
