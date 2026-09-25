#include <ranges>

class Solution {
private:
    std::unordered_map<std::string, std::vector<std::string>> adj;

    void dfs(const std::string& src, std::vector<std::string>& res)
    {
        while (!adj[src].empty())
        {
            std::string dest = adj[src].back();
            adj[src].pop_back();
            dfs(dest, res);
        }
        res.push_back(src);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets)
        {
            adj[t[0]].push_back(t[1]);
        }

        for (auto& [key, edges] : adj)
        {
            std::ranges::sort(edges, std::ranges::greater());
        }

        std::vector<std::string> res;
        dfs("JFK", res);
        std::ranges::reverse(res);
        return res;
    }
};
