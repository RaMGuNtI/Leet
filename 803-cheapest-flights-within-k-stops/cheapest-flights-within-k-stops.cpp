class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, -1}});
        dist[src] = 0;

        while(!q.empty()){
            auto tp = q.front();
            q.pop();
            int u = tp.first;
            int currStops =  tp.second.second;
            int cost = tp.second.first;
            
            for(auto i: adj[u]){
                if(dist[i.first]>cost+i.second && currStops+1<=k){
                    dist[i.first] = cost+i.second;
                    q.push({i.first, {dist[i.first], currStops+1}});
                }
            }
        }
        
        if(dist[dst]==1e9){
            return -1;
        }

        return dist[dst];

    }
};