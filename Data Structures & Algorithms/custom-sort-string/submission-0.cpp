class Solution {
public:
    string customSortString(string order, string s) {
        std::array<int, 26> freq{};
        for (const auto& c : s)
            freq[c - 'a']++;

        std::string res;
        for (const auto& c : order)
        {
            while (freq[c - 'a'])
            {
                res.push_back(c);
                freq[c - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            while (freq[i])
            {
                res.push_back('a' + i);
                freq[i]--;
            }
        }

        return res;
    }
};