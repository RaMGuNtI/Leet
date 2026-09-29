class Solution {
public:
    int dp[105][105][205];

    bool dfs(vector<vector<char>>& grid, int row, int col, int d) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[row][col] == '(') {
            d++;
        } 
        else {
            d--;
        }

        if (d < 0) return false;

        if (d > (m - 1 - row) + (n - 1 - col))
            return false;

        if (dp[row][col][d] != -1)
            return dp[row][col][d];

        if (row == m - 1 && col == n - 1) {
            return dp[row][col][d] = (d == 0);
        }

        bool result = false;

        if (row + 1 < m) {
            result |= dfs(grid, row + 1, col, d);
        }

        if (col + 1 < n) {
            result |= dfs(grid, row, col + 1, d);
        }

        return dp[row][col][d] = result;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        if ((m + n - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')')
            return false;

        return dfs(grid, 0, 0, 0);
    }
};