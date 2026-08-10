class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. check rows
        for (int i = 0; i < 9; i++)
        {
            std::unordered_set<char> seen{};
            for (int j = 0; j < 9; j++)
            {
                char& c = board[i][j];
                if (c == '.')
                    continue;

                if (seen.count(c))
                    return false;

                seen.insert(c);
            }
        }

        // 1. check cols
        for (int i = 0; i < 9; i++)
        {
            std::unordered_set<char> seen{};
            for (int j = 0; j < 9; j++)
            {
                char& c = board[j][i];
                if (c == '.')
                    continue;

                if (seen.count(c))
                    return false;

                seen.insert(c);
            }
        }

        // check squares
        bool valid = validSquare(board, 0, 0)
                    && validSquare(board, 0, 3)
                    && validSquare(board, 0, 6)
                    && validSquare(board, 3, 0)
                    && validSquare(board, 6, 0)
                    && validSquare(board, 3, 3)
                    && validSquare(board, 3, 6)
                    && validSquare(board, 6, 3)
                    && validSquare(board, 6, 6);

        return valid;
    }

    bool validSquare(vector<vector<char>>& board, int row, int col)
    {
        std::unordered_set<char> seen{};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char& c = board[row + i][col + j];
                if (c == '.')
                    continue;

                if (seen.count(c))
                    return false;

                seen.insert(c);
            }
        }

        return true;
    }
};
