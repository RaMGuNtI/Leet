class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(source==destination) return true;
        queue<int> q;
        q.push(source);
        vector<int> vis(n, 0);
        vis[source] = 1;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(int i=0; i<adj[f].size(); i++){
                if(vis[adj[f][i]]==0){
                    q.push(adj[f][i]);
                    vis[adj[f][i]] = 1;
                    if(adj[f][i]==destination) return true;
                }
            }
        }    

        return false;
    }
};