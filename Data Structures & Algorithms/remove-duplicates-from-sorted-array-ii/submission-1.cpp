class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return n;

        int i = 0;
        int j = 0;
        while (j < n)
        {
            int count{1};
            while (j + 1 < n && nums[j] == nums[j + 1])
            {
                count++;
                ++j;
            }
            count = std::min(count, 2);
            for (int k = 0; k < count; ++k)
            {
                nums[i] = nums[j];
                i++;
            }
            ++j;
        }
        return i;
    }
};