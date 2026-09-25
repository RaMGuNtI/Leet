class Solution {
public:
    void dfs(vector<vector<int>>& grid,
             int row,
             int col,
             int m,
             int n,
             int color,
             vector<vector<int>>& vis,
             vector<pair<int,int>>& border) {

        int actualColor = grid[row][col];
        vis[row][col] = 1;

        vector<pair<int,int>> directions = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        bool isBorder = false;

        for (auto dir : directions) {
            int nrow = row + dir.first;
            int ncol = col + dir.second;

            if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n) {
                isBorder = true;
                continue;
            }

            if (grid[nrow][ncol] != actualColor) {
                isBorder = true;
                continue;
            }

            if (!vis[nrow][ncol]) {
                dfs(grid, nrow, ncol, m, n, color, vis, border);
            }
        }

        if (isBorder) {
            border.push_back({row, col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<pair<int,int>> border;

        dfs(grid, row, col, m, n, color, vis, border);

        for (auto cell : border) {
            grid[cell.first][cell.second] = color;
        }

        return grid;
    }
};