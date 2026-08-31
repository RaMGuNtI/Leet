class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        // vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;

        q.push({sr, sc});
        int prevColor = image[sr][sc];
        if(prevColor==color) return image;
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int, int> f = q.front();
            q.pop();

            for(auto dir: directions){
                int nrow = f.first + dir[0];
                int ncol = f.second + dir[1];

                if(nrow<0 || ncol<0 || nrow>=m || ncol>=n) continue;

                if(image[nrow][ncol]==prevColor){
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};