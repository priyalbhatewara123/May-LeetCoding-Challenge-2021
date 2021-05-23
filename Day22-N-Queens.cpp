class Solution {
public:
    vector<vector<string>> ans;
    bitset<20> col, d1, d2;

    void helperFun(int n , vector<string>& board , int row) {
        //base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !d1[row - c + n - 1] && !d2[row + c]) {
                board[row][c] = 'Q';
                col[c] = d1[row - c + n - 1] = d2[row + c] = 1;
                helperFun(n, board, row + 1);

                //backtrack
                board[row][c] = '.';
                col[c] = d1[row - c + n - 1] = d2[row + c] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        helperFun(n, board, 0);
        return ans;
    }
};