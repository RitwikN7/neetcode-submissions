class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = 1;
        int minP = 1;
        int res = nums[0];
        for (int &n : nums)
        {
            int c1 = maxP * n;
            int c2 = minP * n;
            maxP = max(max(c1, c2), n);
            minP = min(min(c1, c2), n);
            res = max(res, maxP);
        }
        return res;
    }
};
