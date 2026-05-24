class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int left = 0;
        int cSum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            cSum += nums[right];
            while (cSum >= target)
            {
                res = min(res, right - left + 1);
                cSum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};