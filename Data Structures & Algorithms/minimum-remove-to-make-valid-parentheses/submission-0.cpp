class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for (const char& c : s)
        {
            if (c == ')')
                close++;
        }

        string res{};
        for (const char& c : s)
        {
            if (c == '(')
            {
                if (open == close)
                    continue;
                
                open++;
            }
            else if (c == ')')
            {
                close--;
                if (open == 0)
                    continue;

                open--;
            }
            res.push_back(c);
        }
        return res;
    }
};
