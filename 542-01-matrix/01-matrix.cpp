class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (auto dir : directions) {

                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow < 0 || nrow >= m ||
                    ncol < 0 || ncol >= n) {
                    continue;
                }

                if (ans[nrow][ncol] != -1) {
                    continue;
                }

                ans[nrow][ncol] = ans[row][col] + 1;

                q.push({nrow, ncol});
            }
        }

        return ans;
    }
};