class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::queue<std::pair<int, int>> q;

        std::array<std::pair<int, int>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

        for (int r = 0; r < ROWS; ++r)
        {
            for (int c = 0; c < COLS; ++c)
            {
                if (grid[r][c] == 0)
                    q.push({r, c});
            }
        }

        int count{};
        while (!q.empty())
        {
            int qSize = q.size();
            for (int i{}; i < qSize; ++i)
            {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& [dr, dc] : dirs)
                {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != INT_MAX)
                        continue;

                    grid[nr][nc] = count + 1;
                    q.push({nr, nc});
                }
            }
            ++count;
        }
    }
};