class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> post(n, 0);
        int maxSeen = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            post[i] = maxSeen;
            maxSeen = max(maxSeen, height[i]);
        }
        maxSeen = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int w = min(maxSeen, post[i]) - height[i];
            if (w > 0)
                res += w;
            maxSeen = max(maxSeen, height[i]);
        }
        return res;
    }
};
