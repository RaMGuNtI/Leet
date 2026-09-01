class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;

        vector<pair<int, int>> litters;

        // Find starting position and all litter positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }

        int k = litters.size();

        // No litter
        if (k == 0)
            return 0;

        /*
            State:

            row
            col
            energy
            mask

            mask tells which litter is cleaned.
        */

        queue<tuple<int, int, int, int>> q;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        // Start
        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;

        int moves = 0;

        int directions[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        // All litter cleaned
        int fullMask = (1 << k) - 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [row, col, currEnergy, mask] = q.front();
                q.pop();

                // All litter cleaned
                if (mask == fullMask)
                    return moves;

                for (auto dir : directions) {

                    int nrow = row + dir[0];
                    int ncol = col + dir[1];

                    // Outside classroom
                    if (nrow < 0 || nrow >= m ||
                        ncol < 0 || ncol >= n)
                        continue;

                    // Wall
                    if (classroom[nrow][ncol] == 'X')
                        continue;

                    // No energy
                    if (currEnergy == 0)
                        continue;

                    int nextEnergy = currEnergy - 1;
                    int nextMask = mask;

                    // If we reach litter
                    for (int i = 0; i < k; i++) {

                        if (litters[i].first == nrow &&
                            litters[i].second == ncol) {

                            nextMask |= (1 << i);
                        }
                    }

                    // Recharge
                    if (classroom[nrow][ncol] == 'R') {
                        nextEnergy = energy;
                    }

                    // Haven't seen this exact state
                    if (!vis[nrow][ncol][nextEnergy][nextMask]) {

                        vis[nrow][ncol][nextEnergy][nextMask] = true;

                        q.push({
                            nrow,
                            ncol,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};