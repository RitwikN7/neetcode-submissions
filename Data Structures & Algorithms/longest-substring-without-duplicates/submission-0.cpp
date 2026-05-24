class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> visit;
        int l = 0;
        int maxSize = 0;
        for (int r = 0; r < s.size(); r++)
        {
            while (visit.find(s[r]) != visit.end())
            {
                visit.erase(s[l]);
                l++;
            }
            visit.insert(s[r]);
            maxSize = max(maxSize, r - l + 1);
        }
        return maxSize;
    }
};
