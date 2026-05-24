class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int n = nums.size();
        int cSum = 0;
        int res = 0;

        for (int right = 0; right < n; right++)
        {
            cSum += nums[right];
            // calculate no. of operations required
            while (left < right && nums[right] * (right - left + 1) - cSum > k)
            {
                cSum -= nums[left];
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};