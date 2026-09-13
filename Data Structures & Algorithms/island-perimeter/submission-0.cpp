class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int r{}; r < ROWS; ++r)
        {
            for (int c{}; c < COLS; ++c)
            {
                if (grid[r][c] == 1)
                    return dfs(grid, r, c);
            }
        }

        return 0;
    }

private:
    int ROWS{};
    int COLS{};
    std::array<std::pair<int, int>, 4> dirs = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
            return 1;

        if (grid[r][c] == -1)
            return 0;

        if (grid[r][c] == 0)
            return 1;

        grid[r][c] = -1;
        int total{};
        for (const auto& d : dirs)
        {
            total += dfs(grid, r + d.first, c + d.second);
        }

        return total;
    }
};