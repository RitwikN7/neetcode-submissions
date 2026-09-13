class DSU
{
public:
    explicit DSU(int n)
        : parent_(n, -1)
        , rank_(n, 0)
    {}

    void addLand(int x)
    {
        if (parent_[x] >= 0)
            return;

        parent_[x] = x;
        count_++;
    }

    bool isLand(int x)
    {
        return parent_[x] >= 0;
    }

    int islandCount() const
    {
        return count_;
    }

    int find(int x)
    {
        if (parent_[x] == x)
            return x;

        return parent_[x] = find(parent_[x]);
    }

    void union_set(int x, int y)
    {
        int a = find(x);
        int b = find(y);

        if (a == b)
            return;

        if (rank_[a] < rank_[b])
            parent_[a] = b;
        else if (rank_[a] > rank_[b])
            parent_[b] = a;
        else
        {
            parent_[b] = a;
            rank_[a]++;
        }
        count_--;
    }


private:
    vector<int> parent_;
    vector<int> rank_;
    int count_{};
};

class Solution {
private:
    const int dirs[5] = {1, 0, -1, 0, 1};

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU dsu(m * n);
        vector<int> res;

        for (const auto& p : positions)
        {
            int index = p[0] * n + p[1];
            dsu.addLand(index);

            for (int i{}; i < 4; ++i)
            {
                int dx = p[0] + dirs[i];
                int dy = p[1] + dirs[i + 1];
                int nei = dx * n + dy;

                if (dx >= 0 && dx < m && dy >= 0 && dy < n && dsu.isLand(nei))
                dsu.union_set(index, nei);
            }

            res.push_back(dsu.islandCount());
        }

        return res;
    }
};
