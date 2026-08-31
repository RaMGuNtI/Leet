class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int key = q.front();
            q.pop();

            for(int i=0; i<rooms[key].size(); i++){
                int next = rooms[key][i]; 
                if (!vis[next]) { 
                    q.push(next); 
                    vis[next] = 1; 
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }

        return true;
    }
};