class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int res = 0;
        int prod = 1;
        for (int r = 0; r < nums.size(); r++)
        {
            prod *= nums[r];
            while (l <= r && prod >= k)
            {
                prod /= nums[l];
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};