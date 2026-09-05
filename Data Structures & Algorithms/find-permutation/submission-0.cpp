class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        stack<int> stk;

        vector<int> res(n + 1);
        int j = 0;

        for (int i = 1; i <= n; i++)
        {
            stk.push(i);
            if (s[i - 1] == 'I')
            {
                while (!stk.empty())
                {
                    res[j++] = stk.top();
                    stk.pop();   
                }
            }
        }

        stk.push(n + 1);
        while (!stk.empty())
        {
            res[j++] = stk.top();
            stk.pop();
        }

        return res;
    }
};
