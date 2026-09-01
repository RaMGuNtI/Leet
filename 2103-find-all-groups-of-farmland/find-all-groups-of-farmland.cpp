class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& land, pair<int,int>& ind){
        vis[row][col] = 1;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(auto dir: directions){
            int nrow = row+dir[0];
            int ncol = col+dir[1];
            if(nrow<0 || ncol<0 || nrow>=land.size() || ncol>=land[0].size()) continue;
            if(vis[nrow][ncol]) continue;
            if(land[nrow][ncol]==1){
                if(ind.first < nrow || ind.second < ncol) ind = {nrow, ncol};
                dfs(nrow, ncol, vis, land, ind);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j]==1 && !vis[i][j]){
                    pair<int, int> ind = {i, j};
                    dfs(i, j, vis, land, ind);
                    ans.push_back({i, j, ind.first, ind.second});
                }                    
            }
        }

        return ans;
    }
};