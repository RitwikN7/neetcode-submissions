class Solution {
public:
    string removeDuplicates(string s, int k) {
        std::vector<std::pair<char, int>> stk;
        for (const char& c : s)
        {
            if (stk.empty() || stk.back().first != c)
                stk.push_back({c, 1});
            else
            {
                stk.back().second++;
                if (stk.back().second == k)
                {
                    stk.pop_back();
                }
            }
        }

        std::string res;
        for (const auto& [c, f] : stk)
        {
            for (int i{}; i < f; ++i)
                res.push_back(c);
        }

        return res;
    }
};