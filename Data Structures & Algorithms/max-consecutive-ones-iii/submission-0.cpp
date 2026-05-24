class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int res = 0;
        int cost = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            cost += (nums[r] == 0);
            while (cost > k)
            {
                cost -= (nums[l] == 0);
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};