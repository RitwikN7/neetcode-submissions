class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
private:
    int atMost(vector<int>& nums, int goal)
    {
        if (goal < 0)
            return 0;

        int cSum = 0;
        int l = 0;
        int res = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            cSum += nums[r];
            while (l <= r && cSum > goal)
            {
                cSum -= nums[l];
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};