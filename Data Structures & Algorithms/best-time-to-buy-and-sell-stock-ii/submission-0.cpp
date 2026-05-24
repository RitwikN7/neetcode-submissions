class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[left])
                res += prices[i] - prices[left];

            left = i;
        }
        return res;
    }
};