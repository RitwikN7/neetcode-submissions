class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals);

        int res{};

        int prev_end = intervals[0][1];

        for (int i{1}; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < prev_end)
            {
                prev_end = std::min(intervals[i][1], prev_end);
                ++res;
            }
            else
                prev_end = intervals[i][1];
        }

        return res;
    }
};
