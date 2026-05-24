class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int LIS = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
                LIS++;
                continue;
            }

            int left = 0;
            int right = dp.size() - 1;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            dp[left] = nums[i];
        }

        return LIS;
    }
};
