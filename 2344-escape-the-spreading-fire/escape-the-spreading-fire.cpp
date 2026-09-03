class Solution {
public:

    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    vector<vector<int>> fireTime(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> fire(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    q.push({i, j});
                    fire[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (auto dir : directions) {

                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if (nrow < 0 || ncol < 0 ||
                    nrow >= m || ncol >= n)
                    continue;

                if (grid[nrow][ncol] == 2)
                    continue;

                if (fire[nrow][ncol] != -1)
                    continue;

                fire[nrow][ncol] = fire[row][col] + 1;

                q.push({nrow, ncol});
            }
        }

        return fire;
    }

    bool canReach(vector<vector<int>>& grid,
                  vector<vector<int>>& fire,
                  int wait) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        q.push({0, 0});
        visited[0][0] = 1;

        int time = wait;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [row, col] = q.front();
                q.pop();

                if (row == m - 1 && col == n - 1)
                    return true;

                for (auto dir : directions) {

                    int nrow = row + dir[0];
                    int ncol = col + dir[1];

                    if (nrow < 0 || ncol < 0 ||
                        nrow >= m || ncol >= n)
                        continue;

                    if (grid[nrow][ncol] == 2)
                        continue;

                    if (visited[nrow][ncol])
                        continue;

                    int arrivalTime = time + 1;

                    if (nrow == m - 1 && ncol == n - 1) {

                        if (fire[nrow][ncol] == -1 ||
                            arrivalTime <= fire[nrow][ncol]) {

                            visited[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }

                    } else {
                        if (fire[nrow][ncol] == -1 ||
                            arrivalTime < fire[nrow][ncol]) {

                            visited[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }

            time++;
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> fire = fireTime(grid);

        int low = 0;
        int high = m * n + 1;
        int answer = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canReach(grid, fire, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (answer == m * n + 1)
            return 1000000000;

        return answer;
    }
};