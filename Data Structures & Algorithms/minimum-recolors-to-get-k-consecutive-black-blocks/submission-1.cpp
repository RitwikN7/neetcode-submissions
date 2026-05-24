class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int ops = 0;
        int res = INT_MAX;
        for (int right = 0; right < blocks.size(); right++)
        {
            if (right - left + 1 > k)
            {
                if (blocks[left] == 'W')
                    ops--;
                
                left++;
            }
            if (blocks[right] == 'W')
                ops++;

            if (right - left + 1 == k)
                res = min(res, ops);
        }
        return res;
    }
};