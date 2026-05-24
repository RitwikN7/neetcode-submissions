class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int cur = 0;
        int res = 0;
        int bit = -1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cur = (bit == 0) ? cur + 1 : 1;
                bit = 1;
            }
            else if (arr[i] < arr[i + 1])
            {
                cur = (bit == 1) ? cur + 1 : 1;
                bit = 0;
            }
            else
            {
                bit = -1;
                cur = 0;
            }
            res = max(res, cur);
        }
        return res + 1;
    }
};