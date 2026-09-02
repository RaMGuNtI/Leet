class Solution {
public:
    bool isaLock(char character){
        return isalpha(character) && isupper(character);
    }

    bool isAKey(char character){
        return isalpha(character) && islower(character);
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();

        // row, col, moves, keys collected
        queue<tuple<int, int, int, string>> q;
        map<tuple<int, int, string>, int> vis;
        int keysNeeded = 0;
        int sr, sc;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='@'){
                    sr = i;
                    sc = j;
                }

                if(isAKey(grid[i][j])) keysNeeded++;
            }
        }
        string keysString(keysNeeded, '0');

        q.push({sr, sc, 0, keysString});
        vis[{sr, sc, keysString}] = 1;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            auto [row, col, moves, keysCollected] = q.front();
            q.pop();
            if(count(keysCollected.begin(), keysCollected.end(), '1')==keysNeeded) return moves;
            

            for(auto dir: directions){
                int nrow = row+dir.first;
                int ncol = col+dir.second;

                if(nrow<0 || ncol<0 || nrow>=m || ncol>=n) continue;
                char newChunkChar = grid[nrow][ncol];
                string newKeyCollection = keysCollected;
                if(isAKey(newChunkChar)) newKeyCollection[newChunkChar-'a'] = '1';
                if(isaLock(newChunkChar)){
                    if(keysCollected[tolower(newChunkChar)-'a']=='0') continue;
                }

                if(newChunkChar=='@' || newChunkChar=='.' || isAKey(newChunkChar) || isaLock(newChunkChar)){
                    if(!vis.contains({nrow, ncol, newKeyCollection})){
                        q.push({nrow, ncol, moves+1, newKeyCollection});
                        vis[{nrow, ncol, newKeyCollection}]=1;
                    }
                }
            }
        }

        return -1;
    }
};