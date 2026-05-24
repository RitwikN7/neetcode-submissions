class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> par2Child;
        int n = pid.size();
        for (int i = 0; i < n; i++)
        {
            par2Child[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (const auto& c : par2Child[curr])
                q.push(c);
        }
        return res;
    }
};
