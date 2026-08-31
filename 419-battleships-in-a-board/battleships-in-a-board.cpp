class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& board){
        vis[row][col] = true;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(auto dir: directions){
            int nrow = row+dir[0];
            int ncol = col+dir[1];

            if(nrow<board.size() && ncol<board[0].size() && !vis[nrow][ncol] && board[nrow][ncol]=='X'){
                dfs(nrow, ncol, vis, board);
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> vis(rows, vector<bool> (cols, false));
        int count = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    dfs(i, j, vis, board);
                    count++;
                }
            }
        }

        return count;
    }
};