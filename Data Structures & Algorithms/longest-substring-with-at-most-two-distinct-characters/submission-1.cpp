class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int l = 0;
        int res = 0;
        unordered_map<char, int> cache{};
        for (int r = 0; r < n; r++)
        {
            cache[s[r]]++;
            while (cache.size() > 2)
            {
                cache[s[l]]--;

                if (cache[s[l]] == 0)
                    cache.erase(s[l]);

                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};