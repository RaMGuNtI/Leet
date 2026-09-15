class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto i: times){
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int v = pq.top().second;
            pq.pop();

            for(auto i: adj[v]){
                if(dist[i.first]>dist[v]+i.second){
                    dist[i.first] = dist[v]+i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        if(ans==INT_MAX) return -1;
        return ans;
    }
};