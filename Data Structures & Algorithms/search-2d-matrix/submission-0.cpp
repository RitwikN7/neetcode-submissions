class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int l = 0;
        int r = M * N - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int row = m / N;
            int col = m % N;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return false;
    }
};
