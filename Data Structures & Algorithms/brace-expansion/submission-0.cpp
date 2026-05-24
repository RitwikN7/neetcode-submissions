class Solution {
private:
    vector<string> res{};
    int N{};

    void dfs(string& s, int i, string& cur)
    {
        if (i == N)
        {
            res.push_back(cur);
            return;
        }

        if (s[i] != '{')
        {
            cur.push_back(s[i]);
            dfs(s, i + 1, cur);
            cur.pop_back();
            return;
        }

        int idx = i + 1;
        int endIdx = s.find('}', idx);
        while (idx < N)
        {
            if (s[idx] == '}')
                break;

            if (s[idx] == ',')
            {
                idx++;
                continue;
            }

            cur.push_back(s[idx]);
            dfs(s, endIdx + 1, cur);
            cur.pop_back();

            idx++;
        }
    }

public:
    vector<string> expand(string s) {
        N = s.size();
        string cur{};
        dfs(s, 0, cur);
        return res;
    }
};
