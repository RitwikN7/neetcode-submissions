class TicTacToe {
public:
    TicTacToe(int n) {
        N = n;
        rows.resize(n);
        cols.resize(n);
    }
    
    int move(int row, int col, int player) {
        rows[row].addMove(player - 1);

        if (rows[row].counts[player - 1] == N)
            return player;

        cols[col].addMove(player - 1);

        if (cols[col].counts[player - 1] == N)
            return player;

        if (row == col)
        {
            diag[0].addMove(player - 1);
            if (diag[0].counts[player - 1] == N)
                return player;
        }

        if (row == N - col - 1)
        {
            diag[1].addMove(player - 1);
            if (diag[1].counts[player - 1] == N)
                return player;
        }

        return 0;
    }
    
private:
    struct Sequence
    {
        int counts[2] = {0, 0};

        void addMove(int player)
        {
            counts[player]++;
        }
    };

    vector<Sequence> rows{};
    vector<Sequence> cols{};
    Sequence diag[2];
    int N{};
};
