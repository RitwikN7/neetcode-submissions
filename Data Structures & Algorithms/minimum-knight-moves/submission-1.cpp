class Solution {
public:
    int minKnightMoves(int x, int y) {
        memo.clear();
        return dfs(abs(x), abs(y));
    }
private:
    std::unordered_map<std::string, int> memo;

    int dfs(int x, int y)
    {
        std::string key = std::to_string(x) + "|" + std::to_string(y);
        auto iter = memo.find(key);
        if (iter != memo.end())
            return iter->second;

        if (x + y == 0)
            return 0;

        if (x + y == 2)
            return 2;

        int moves = std::min(dfs(abs(x - 1), abs(y - 2)),
                             dfs(abs(x - 2), abs(y - 1))) + 1;
        return memo[key] = moves;
    }
};
