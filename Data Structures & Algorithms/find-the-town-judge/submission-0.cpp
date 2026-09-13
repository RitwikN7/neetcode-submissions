class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::vector<int> indegree(n + 1, 0);
        std::vector<int> outdegree(n + 1, 0);
        for (const auto& t : trust)
        {
            indegree[t[1]]++;
            outdegree[t[0]]++;
        }

        for (int i{1}; i <= n; i++)
        {
            if (outdegree[i] == 0 && indegree[i] == n - 1)
                return i;
        }

        return -1;
    }
};