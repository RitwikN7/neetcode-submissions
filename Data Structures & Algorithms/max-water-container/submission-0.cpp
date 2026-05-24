class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxSize = 0;
        while (left < right)
        {
            int cur = (right - left) * min(heights[left], heights[right]);
            maxSize = max(maxSize, cur);
            if (heights[left] <= heights[right])
                left++;
            else
                right--;
        }
        return maxSize;
    }
};
