class Solution {
public:
    void dfs(vector<vector<bool>> &vis, int row, int col, vector<vector<char>>& grid){
        vis[row][col] = true;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i=0; i<4; i++){
            int nrow = row+directions[i][0];
            int ncol = col+directions[i][1];
            if(nrow<grid.size() && ncol<grid[0].size()){
                if(grid[nrow][ncol]=='1' && !vis[nrow][ncol]) dfs(vis, nrow, ncol, grid);
            }                
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(vis, i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};