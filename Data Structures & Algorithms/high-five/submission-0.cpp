class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<>>> scores;
        for (const auto& e : items)
        {
            const int& id = e[0];
            const int& score = e[1];
            scores[id].push(score);
            if (scores[id].size() > 5)
                scores[id].pop();
        }

        vector<vector<int>> res;
        for (auto& e : scores)
        {
            int total = 0;
            while (!e.second.empty())
            {
                total += e.second.top();
                e.second.pop();
            }
            res.push_back({e.first, total / 5});
        }
        return res;

    }
};
