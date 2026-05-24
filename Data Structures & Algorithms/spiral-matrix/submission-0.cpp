class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int left = 0;
        int top = 0;
        while (left < n && top < m)
        {
            for (int i = left; i < n; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < m; i++)
            {
                res.push_back(matrix[i][n - 1]);
            }
            n--;
            if (!(top < m && left < n))
                break;
                
            for (int i = n - 1; i >= left; i--)
            {
                res.push_back(matrix[m - 1][i]);
            }
            m--;
            for (int i = m - 1; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;

        }
        return res;

    }
};
