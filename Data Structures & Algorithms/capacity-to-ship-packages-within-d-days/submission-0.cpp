class Solution {
public:
    bool helper(vector<int>& weights, int days, int cap)
    {
        int cnt = 1;
        int curr = 0;
        for (int w : weights)
        {
            if (curr + w > cap)
            {
                cnt++;
                curr = 0;
            }
            if (cnt > days)
                return false;

            curr += w;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        int res = INT_MAX;
        for (int w : weights)
            right += w;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (helper(weights, days, mid))
            {
                right = mid - 1;
                res = min(res, mid);
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};