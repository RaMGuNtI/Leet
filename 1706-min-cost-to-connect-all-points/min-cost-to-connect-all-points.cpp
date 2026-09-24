class Solution {
public:
    int getDist(vector<int> p1, vector<int> p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int dist = getDist(points[i], points[j]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<bool> vis(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        int cost = 0;
        while(!pq.empty()){
            pair<int, int> tp = pq.top();
            pq.pop();
            if(vis[tp.second]){
                continue;
            }

            vis[tp.second] = true;
            cost+=tp.first;


            for(auto i: adj[tp.second]){
                if(!vis[i.first]){
                    pq.push({i.second, i.first});
                }
            }
        }

        return cost;
    }
};