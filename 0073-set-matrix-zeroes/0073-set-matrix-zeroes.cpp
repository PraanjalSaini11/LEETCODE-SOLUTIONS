class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // Check if first row has 0
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                firstRow = true;
        }

        // Check if first column has 0
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;
        }

        // Use first row and first column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set marked rows to 0
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }

        // Set marked columns to 0
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }

        // Finally handle first row and first column
        if (firstRow) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        if (firstCol) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};