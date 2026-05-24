class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int l = 0;
        int r = nums.size() - 1;
        int p = res.size() - 1;
        while (l <= r)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                res[p] = nums[l] * nums[l];
                l++;
            }
            else
            {
                res[p] = nums[r] * nums[r];
                r--;
            }
            p--;
        }
        return res;
    }
};