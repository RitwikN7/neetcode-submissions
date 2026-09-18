class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();

        int diff = (arr.back() - arr.front()) / n;
        int left{0};
        int right{n - 1};

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == arr.front() + mid * diff)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return arr.front() + diff * left;
    }
};
