class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::vector<std::vector<int>> res;
        int i{};
        int j{};

        while (i < firstList.size() && j < secondList.size())
        {
            int start = std::max(firstList[i][0], secondList[j][0]);
            int end = std::min(firstList[i][1], secondList[j][1]);

            if (start <= end)
            {
                res.push_back({start, end});
            }

            if (firstList[i][1] < secondList[j][1])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }

        return res;    
    }
};