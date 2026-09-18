/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int ROWS = dim[0];
        int COLS = dim[1];

        int res = COLS;
        for (int r{}; r < ROWS; ++r)
        {
            int left{0};
            int right{COLS - 1};
            if (binaryMatrix.get(r, left))
                return 0;

            if (!binaryMatrix.get(r, right))
                continue;

            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (binaryMatrix.get(r, mid))
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }

            res = std::min(res, right);
        }

        return res == COLS ? -1 : res;
    }
};
