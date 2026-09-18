class Solution {
public:
    string decodeString(string s) {
        vector<std::pair<std::string, int>> stk;
        int i{};
        std::string res;
        int k{};
        while (i < s.size())
        {
            if (std::isdigit(s[i]))
            {
                k = k * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                stk.push_back({"", k});
                k = 0;
            }
            else if (s[i] == ']')
            {
                auto [sub, c] = stk.back();
                std::string repeated;
                for (int j{}; j < c; ++j)
                {
                    repeated += sub;
                }
                stk.pop_back();
                if (stk.empty())
                    res += repeated;
                else
                    stk.back().first += repeated;
            }
            else
            {
                if (stk.empty())
                {
                    res.push_back(s[i]);
                }
                else
                    stk.back().first.push_back(s[i]);
            }
            ++i;
        }

        return res;
    }
};