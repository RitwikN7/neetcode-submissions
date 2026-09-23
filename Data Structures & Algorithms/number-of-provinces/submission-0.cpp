class DSU
{
public:
    explicit DSU(int n)
        : parent(n)
        , rank(n)
        , components(n)
    {
        for (int i{}; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSets(int a, int b)
    {
        int p = findParent(a);
        int q = findParent(b);

        if (p == q)
            return;

        if (rank[q] > rank[p])
        {
            parent[p] = q;
            rank[q] += rank[p];
        }
        else
        {
            parent[q] = p;
            rank[p] += rank[q];
        }

        components--;
    }

    int getComponents() const
    {
        return components;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int components{};
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j || isConnected[i][j] == 0)
                    continue;

                dsu.unionSets(i, j);
            }
        }

        return dsu.getComponents();
    }
};