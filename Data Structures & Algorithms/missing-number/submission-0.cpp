class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_res = 0;
        for (int i = 0; i <= n; i++)
        {
            xor_res ^= i;
        }

        for (const auto& num : nums)
        {
            xor_res ^= num;
        }

        return xor_res;
    }
};
