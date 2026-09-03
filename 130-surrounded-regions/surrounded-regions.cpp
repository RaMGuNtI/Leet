class Solution {
public:
    vector<pair<int, int>> pairsToUp;

    void resetPairs(){
        pairsToUp = {};
    }

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int &invalid){
        vis[row][col] = 1;
        pairsToUp.push_back({row, col});

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(auto dir: directions){
            int nrow = row+dir.first;
            int ncol = col+dir.second;

            if(nrow<0 || ncol<0 || nrow>=board.size() || ncol>=board[0].size()){
                invalid++;
                continue;
            }

            if(vis[nrow][ncol] || board[nrow][ncol]!='O') continue;
            dfs(nrow, ncol, board, vis, invalid);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    int invalid = 0;
                    dfs(i, j, board, vis, invalid);

                    if(invalid==0){
                        for(int i=0; i<pairsToUp.size(); i++){
                            board[pairsToUp[i].first][pairsToUp[i].second] = 'X';
                        }
                    }
                    resetPairs();
                }
            }
        }
    }
};