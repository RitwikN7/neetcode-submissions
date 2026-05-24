class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0;
        int res = 0;
        for (int n : nums)
        {
            if (n == 0)
            {
                cur = 0;
            }
            else
            {
                cur++;
                res = max(res, cur);
            }
        }
        return res;
    }
};