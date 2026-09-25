#include <ranges>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pii = std::pair<int, int>;
        vector<vector<pii>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        for (const auto& edge : times)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
        pq.push({0, k});
        while (!pq.empty())
        {
            auto [t, node] = pq.top();
            pq.pop();
            if (dist[node] < t)
                continue;

            for (const auto& [nei, d] : adj[node])
            {
                int new_time = t + d;
                if (new_time < dist[nei])
                {
                    dist[nei] = new_time;
                    pq.push({new_time, nei});
                }
            }
        }

        bool not_visited = std::ranges::any_of(dist | std::ranges::views::drop(1), [](int d) { return d == INT_MAX; });

        if (not_visited)
            return -1;

        return *std::ranges::max_element(dist.begin() + 1, dist.end());
    }
};
