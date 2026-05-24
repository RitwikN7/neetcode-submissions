class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1)
            return k;
        int dp0 = k;
        int dp1 = k * k;
        for (int i = 2; i < n; i++)
        {
            int dp2 = (k - 1) * (dp0 + dp1);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1;
    }
};
