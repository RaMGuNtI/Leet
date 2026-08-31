class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int minutes = 0;

        int ones = 0;
        while(true){
            vector<pair<int, int>> toChange;
            ones = 0;
            for(int row = 0; row<rows; row++){
                for(int col = 0; col<cols; col++){
                    if(grid[row][col]==1){
                        ones++;
                        for(auto dir: directions){
                            int nrow = row+dir[0];
                            int ncol = col+dir[1];

                            if(nrow>=0 && ncol>=0 && nrow<rows && ncol<cols && grid[nrow][ncol]==2){
                                toChange.push_back({row, col});
                                break;
                            }
                        }
                    }
                }
            }

            if(toChange.size()==0){
                break;
            }

            for(auto i: toChange){
                grid[i.first][i.second] = 2;
            }

            minutes++;
        }


        if(ones==0) return minutes;
        return -1;
    }
};