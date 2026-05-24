class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (auto& intv : intervals)
        {
            // if interval precedes toBeRemoved
            if (intv[1] < toBeRemoved[0] || intv[0] > toBeRemoved[1])
            {
                res.push_back(intv);
                continue;
            }

            if (intv[0] < toBeRemoved[0])
                res.push_back({intv[0], toBeRemoved[0]});

            if (intv[1] > toBeRemoved[1])
                res.push_back({toBeRemoved[1], intv[1]});
        }
        return res;
    }
};
