class Solution {
private:
    vector<vector<int>> dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // for (int i = m - 1; i >= 0; i--)
        // {
        //     for (int j = n - 1; j >= 0; j--)
        //     {
        //         if (text1[i] == text2[j])
        //             dp[i][j] = 1 + dp[i + 1][j + 1];
        //         else
        //             dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        //     }
        // }
        // return dp[0][0];

        dp.assign(m, vector<int>(n, -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(const string& s1, const string& s2, int i, int j)
    {
        if (i == s1.size() || j == s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            dp[i][j] = 1 + dfs(s1, s2, i + 1, j + 1);
        else
            dp[i][j] = max(dfs(s1, s2, i, j + 1), dfs(s1, s2, i + 1, j));
        
        return dp[i][j];
    }
};
