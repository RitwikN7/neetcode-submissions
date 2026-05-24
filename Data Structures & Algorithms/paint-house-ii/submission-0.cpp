class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<int> dp = costs[0];
        for (int i = 1; i < n; i++)
        {
            vector<int> nextdp = costs[i];
            pair<int, int> min1 = {INT_MAX, -1};
            pair<int, int> min2 = {INT_MAX, -1};
            for (int j = 0; j < k; j++)
            {
                if (dp[j] < min1.first)
                {
                    min2 = min1;
                    min1 = {dp[j], j};
                }
                else if (dp[j] < min2.first)
                    min2 = {dp[j], j};
            }
            for (int j = 0; j < k; j++)
            {
                if (j != min1.second)
                    nextdp[j] += min1.first;
                else
                    nextdp[j] += min2.first;
            }

            dp = nextdp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
