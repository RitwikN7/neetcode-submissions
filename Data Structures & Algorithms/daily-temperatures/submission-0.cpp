class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk; // temp, index
        vector<int> res(temperatures.size());
        stk.push(make_pair(temperatures[0], 0));
        for (int i = 1; i < temperatures.size(); i++)
        {
            while (stk.size() && temperatures[i] > stk.top().first)
            {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push(make_pair(temperatures[i], i));
        }

        return res;
    }
};
