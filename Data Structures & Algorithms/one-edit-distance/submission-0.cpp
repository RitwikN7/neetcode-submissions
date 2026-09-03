class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t)
            return false;

        size_t ns = s.size();
        size_t nt = t.size();

        if (ns > nt)
            return isOneEditDistance(t, s);

        if (nt - ns > 1)
            return false;

        for (size_t i = 0; i < ns; i++)
        {
            if (s[i] != t[i])
            {
                if (ns == nt)
                    return s.substr(i + 1) == t.substr(i + 1);

                return s.substr(i) == t.substr(i + 1);
            }
        }

        return (nt - ns == 1);
    }
};
