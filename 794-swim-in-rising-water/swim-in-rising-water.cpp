class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        dist[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();

            int diff = tp.first;
            int row = tp.second.first;
            int col = tp.second.second;

            if(row==n-1 && col==n-1) return diff;

            for(auto dir: directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow<0 || ncol<0 || nrow>=n || ncol>=n) continue;
                int newEffort = max(diff, grid[nrow][ncol]);
                if(dist[nrow][ncol]>newEffort){
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort, {nrow, ncol}});
                }
            }
        }

        return 0;
    }
};