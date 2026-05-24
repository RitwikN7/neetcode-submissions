class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] % 2 == 0)
            {
                swap(nums[l], nums[r]);
                l++;
            }
        }
        return nums;
    }
    
};