
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<vector<int>> q;
        q.push({0, 0, 1});

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
            {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
        };

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr[0];
            int col = curr[1];
            int dist = curr[2];

            if (row == n - 1 && col == n - 1)
                return dist;

            for (auto dir : directions) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if (nrow >= 0 && ncol >= 0 &&
                    nrow < n && ncol < n &&
                    grid[nrow][ncol] == 0 &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol, dist + 1});
                }
            }
        }

        return -1;
    }
};
