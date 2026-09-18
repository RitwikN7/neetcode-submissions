class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        size_t n = heights.size();
        vector<int> res(n, 0);
        std::stack<size_t> stk;
        for (size_t i{}; i < n; ++i)
        {
            while (!stk.empty() && heights[i] > heights[stk.top()])
            {
                res[stk.top()]++;
                stk.pop();
            }

            if (!stk.empty())
            {
               res[stk.top()]++; 
            }

            stk.push(i);
        }

        return res;
    }
};