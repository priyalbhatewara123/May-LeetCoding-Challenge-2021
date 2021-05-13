class NumMatrix {
    vector<vector<int>> cumMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        cumMatrix = matrix;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int col = 1; col < n; col++) {
            for (int row = 0; row < m; row++) {
                cumMatrix[row][col] = cumMatrix[row][col - 1] + cumMatrix[row][col];
            }
        }

        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                cumMatrix[row][col] = cumMatrix[row - 1][col] + cumMatrix[row][col];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = cumMatrix[row2][col2];

        if (row1 > 0) {
            sum -= cumMatrix[row1 - 1][col2];
        }

        if (col1 > 0) {
            sum -= cumMatrix[row2][col1 - 1];
        }

        if (row1 > 0 and col1 > 0) {
            sum += cumMatrix[row1 - 1][col1 - 1];
        }

        return sum;
    }
};