class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();

            int diff = tp.first;
            int row = tp.second.first;
            int col = tp.second.second;

            if(row==n-1 && col==m-1) return diff;

            for(auto dir: directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow<0 || ncol<0 || nrow>=n || ncol>=m) continue;
                int newDiff = max(abs(heights[nrow][ncol]-heights[row][col]), diff);
                if(dist[nrow][ncol]>newDiff){
                    dist[nrow][ncol] = newDiff;
                    pq.push({newDiff, {nrow, ncol}});
                }
            }
        }

        return 0;
    }
};