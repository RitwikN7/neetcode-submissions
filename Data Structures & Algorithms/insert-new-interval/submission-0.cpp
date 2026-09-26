#include <ranges>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res;
        res.reserve(intervals.size());

        for (int i{}; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > newInterval[1])
            {
                res.push_back(newInterval);
                std::ranges::copy(intervals | std::ranges::views::drop(i), std::back_inserter(res));
                return res;
            }
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
                continue;
            }

            newInterval = {std::min(newInterval[0], intervals[i][0]),
                           std::max(newInterval[1], intervals[i][1])};

        }

        res.push_back(newInterval);
        return res;
    }
};
