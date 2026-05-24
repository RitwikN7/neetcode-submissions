class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        int p = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
                k--;
            else
            {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        return k;
    }
};