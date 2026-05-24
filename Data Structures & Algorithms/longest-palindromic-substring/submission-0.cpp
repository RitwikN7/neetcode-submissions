class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 0;
        int resIdx = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i > -1; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j] &&
                (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    if (j - i + 1 > resLen)
                    {
                        resLen = j - i + 1;
                        resIdx = i;
                    }
                }
            }
        }
        return s.substr(resIdx, resLen);
    }
};
