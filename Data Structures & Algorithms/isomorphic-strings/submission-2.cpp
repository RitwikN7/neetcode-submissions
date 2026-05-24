class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        int n = s.size();
        unordered_map<char,char> c;
        unordered_set<char> x;
        for (int i = 0; i < n; i++)
        {
            if (c.find(s[i]) == c.end())
            {
                if (x.find(t[i]) != x.end())
                    return false;
                c[s[i]] = t[i];
                x.insert(t[i]);
            }
            else
            {
                if (c[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};