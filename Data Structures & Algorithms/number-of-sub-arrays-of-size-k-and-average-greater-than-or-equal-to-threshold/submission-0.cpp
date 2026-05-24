class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int rSum = 0;
        int res = 0;
        for (int right = 0; right < arr.size(); right++)
        {
            if (right - left + 1 > k)
            {
                rSum -= arr[left];
                left++;
            }
            rSum += arr[right];
            if (right - left + 1 == k)
            {
                if (rSum / k >= threshold)
                    res++;
            }
        }
        return res;
    }
};