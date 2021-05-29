/*
(Backtracking + Bitset O(N))
Time Complexity : O(N!) we have N choices in the first row, N-1 in the second row,
N-2 in the next and so on... which brings overall time complexity to O(N!)
Space Complexity : O(N), for recursive stack
*/

class Solution {
public:
	bitset<20> col , d1 , d2;

	void totalWays(int row , int n , int& ans) {
		if (row == n) {
			ans++;
			return;
		}
		for (int c = 0; c < n; c++) {
			if (!col[c] && !d1[row + c] && !d2[row - c + n - 1]) {
				col[c] = d1[row + c] = d2[row - c + n - 1] = 1;
				totalWays(row + 1, n, ans);

				col[c] = d1[row + c] = d2[row - c + n - 1] = 0;
			}
		}
	}

	int totalNQueens(int n) {
		int ans = 0;
		totalWays(0, n, ans);
		return ans;
	}
};
