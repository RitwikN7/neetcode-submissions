class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<char> stk;
        for(auto &op : logs)
        {
            if (op == "../")
            {
                if (!stk.empty())
                    stk.pop();
            }
            else if (op != "./")
                stk.push('\0');
        }
        return stk.size();
    }
};