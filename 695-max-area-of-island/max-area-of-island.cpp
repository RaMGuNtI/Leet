class Solution {
public:
    int dfs(vector<vector<int>>& grid,
            vector<vector<bool>>& visited,
            int row,
            int col) {

        visited[row][col] = true;

        int currSum = 1;

        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        for (int i = 0; i < dirs.size(); i++) {

            int nr = row + dirs[i].first;
            int nc = col + dirs[i].second;

            if (0 <= nr && nr < grid.size() &&
                0 <= nc && nc < grid[0].size() &&
                !visited[nr][nc] &&
                grid[nr][nc] == 1) {

                currSum += dfs(grid, visited, nr, nc);
            }
        }

        return currSum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(
            rows, vector<bool>(cols, false)
        );

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {

                    ans = max(
                        ans,
                        dfs(grid, visited, i, j)
                    );
                }
            }
        }

        return ans;
    }
};