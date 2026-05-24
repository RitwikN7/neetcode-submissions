class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int cur = 0;
        int res = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            cur += (gas[i] - cost[i]);
            if (cur < 0)
            {
                cur = 0;
                res = i + 1;
            }
        }
        return res;
    }
};
