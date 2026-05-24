class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int res = 0;
        for (auto& elem : tokens)
        {
            try
            {
                int num = stoi(elem);
                stk.push(num);
            }
            catch (...)
            {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                if (elem == "+")
                    stk.push(first + second);
                else if (elem == "-")
                    stk.push(first - second);
                else if (elem == "*")
                    stk.push(first * second);
                else
                    stk.push(first / second);
            }
        }
        return stk.top();
    }
};
