class Solution {
private:
    const int WHITE = 0;
    const int BLACK = 1;
    const int GREY = 2;
    vector<vector<int>> adj;

    bool dfs(int node, int target, vector<int>& vis)
    {
        if (vis[node] != WHITE)
            return vis[node] == BLACK;

        if (adj[node].size() == 0)
            return node == target;

        vis[node] = GREY;
        for (const auto& nei : adj[node])
        {
            if (!dfs(nei, target, vis))
                return false;
        }
        vis[node] = BLACK;
        return true;
    }

public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n);
        for (const auto& e : edges)
            adj[e[0]].push_back(e[1]);

        if (adj[destination].size() != 0)
            return false;

        vector<int> visited(n, WHITE);
        return dfs(source, destination, visited);
    }
};
