class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (const auto& op : operations)
        {
            if (op == "+")
            {
                stk.push_back(stk[stk.size() - 1] + stk[stk.size() - 2]);
            }
            else if (op == "D")
            {
                stk.push_back(stk[stk.size() - 1] * 2);
            }
            else if (op == "C")
            {
                stk.pop_back();
            }
            else
                stk.push_back(std::stoi(op));
        }

        return std::accumulate(stk.begin(), stk.end(), 0);
    }
};