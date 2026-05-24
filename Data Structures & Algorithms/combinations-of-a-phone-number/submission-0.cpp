class Solution {
private:
    vector<string> res{};
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;
        string sub{};
        dfs(digits, sub, 0);
        return res;
    }

    void dfs(string &digits, string &sub, int i)
    {
        if (i == digits.size())
        {
            res.push_back(sub);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for (auto &c : chars)
        {
            sub.push_back(c);
            dfs(digits, sub, i + 1);
            sub.pop_back();
        }
    }
};
