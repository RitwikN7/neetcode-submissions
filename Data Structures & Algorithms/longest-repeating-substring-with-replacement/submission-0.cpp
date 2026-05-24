class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<char, int> freq = {}; // O(1) space as only 26 entries
        int maxFreq = 0;
        int res = 0;
        for (int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            while (r - l + 1 - maxFreq > k)
            {
                freq[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;

    }
};
