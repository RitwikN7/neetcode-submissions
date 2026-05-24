class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int n = s.size();
        vector<bool> toBold(n, false);
        for (const auto& w : words)
        {
            int start = s.find(w);
            while (start != -1)
            {
                for (int i = 0; i < w.size(); i++)
                    toBold[start + i] = true;

                start = s.find(w, start + 1);
            }
        }
        const string open = "<b>";
        const string close = "</b>";
        string res{};
        for (int i = 0; i < n; i++)
        {
            if (toBold[i] && (i == 0 || !toBold[i - 1]))
                res += open;

            res += s[i];

            if (toBold[i] && (i == n - 1 || !toBold[i + 1]))
                res += close;
        }
        return res;
    }
};
