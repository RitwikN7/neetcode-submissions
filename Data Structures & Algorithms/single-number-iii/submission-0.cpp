class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for (const auto& n : nums)
        {
            xor_all ^= n;
        }

        int diff_bit = 1;
        while ((xor_all & diff_bit) == 0)
            diff_bit <<= 1;

        int a = 0;
        int b = 0;
        for (const auto& n : nums)
        {
            if (n & diff_bit)
                a ^= n;
            else
                b ^= n;
        }

        return {a, b};
    }
};