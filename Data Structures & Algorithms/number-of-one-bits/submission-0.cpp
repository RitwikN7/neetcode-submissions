class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bit = 1;
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & bit)
                res++;
            bit <<= 1;
        }

        return res;
    }
};
