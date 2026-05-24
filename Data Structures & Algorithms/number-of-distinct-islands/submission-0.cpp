class Solution {
private:
    int ROWS;
    int COLS;
    unordered_set<string> vis;
    const int dirs[5] = {1, 0, -1, 0, 1};

    string dfs(vector<vector<int>>& grid, int r, int c, const int& sRow, const int& sCol)
    {
        if (r < 0 || r >= ROWS ||
            c < 0 || c >= COLS ||
            grid[r][c] != 1)
            return "";

        grid[r][c] = -1;
        string res = to_string(r - sRow) + "," + to_string(c - sCol) + "|";
        for (int i = 0; i < 4; i++)
        {
            res += dfs(grid, r + dirs[i], c + dirs[i + 1], sRow, sCol);
        }
        return res;
    }

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        vis.clear();
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (grid[r][c] == 1)
                {
                    string ser = dfs(grid, r, c, r, c);
                    vis.insert(ser);
                }
            }
        }

        return vis.size();
    }
};
