class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        using pii = std::pair<int, int>;
        std::vector<int> count(n, 0);
        std::ranges::sort(meetings);

        std::priority_queue<pii, std::vector<pii>, std::greater<>> min_heap;

        for (int i{}; i < n; ++i)
        {
            min_heap.push({0, i});
        }

        for (int i{}; i < meetings.size(); ++i)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];
            while (!min_heap.empty() && min_heap.top().first < start)
            {
                auto [end_time, room] = min_heap.top();
                min_heap.pop();
                min_heap.push({start, room});
            }

            auto [end_time, room] = min_heap.top();
            min_heap.pop();

            min_heap.push({end_time + (end - start), room});
            count[room]++;
        }

        int max_idx{};
        for (int i{}; i < n; ++i)
        {
            if (count[i] > count[max_idx])
            {
                max_idx = i;
            }
        }

        return max_idx;
    }
};