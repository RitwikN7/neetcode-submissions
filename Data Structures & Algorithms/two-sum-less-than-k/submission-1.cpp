class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        if (nums.size() <= 1)
            return -1;

        std::ranges::sort(nums);
        size_t left{};
        size_t right{nums.size() - 1};
        int res{-1};
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < k)
            {
                res = std::max(res, sum);
                ++left;
            }
            else
                --right;
        }
        return res;
    }
};
