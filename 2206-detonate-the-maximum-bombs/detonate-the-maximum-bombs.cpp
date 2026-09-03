class Solution {
public:
    void dfs(int curr, vector<vector<int>> &adj, vector<int> &vis, int &maxi){
        vis[curr] = 1;
        maxi++;

        for(int i: adj[curr]){
            if(vis[i]) continue;
            dfs(i, adj, vis, maxi);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int numBombs = bombs.size();
        
        vector<vector<int>> adj(numBombs);
        int ans = INT_MIN;
        
        for(int i=0; i<numBombs; i++){
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long rad1 = bombs[i][2];
            for(int j=0; j<numBombs; j++){
                if(i==j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                // int rad2 = bombs[j][2];
                long long diffSq1 = pow((x2-x1), 2);
                long long diffSq2 = pow((y2-y1), 2);
                long long radSq = rad1*rad1;
                if(diffSq1+diffSq2<=(radSq)){
                    adj[i].push_back(j);
                }
            }
        }
        
        for(int i=0; i<numBombs; i++){
            vector<int> vis(numBombs, 0);
            int maxi = 0;
            dfs(i, adj, vis, maxi);
            ans = max(maxi, ans);
        }

        return ans;
    }
};