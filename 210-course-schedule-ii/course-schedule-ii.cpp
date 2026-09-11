class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indegree(numCourses, 0);

        for(auto i : adj) {
            for(int j : i) {
                indegree[j]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int fr = q.front();
            q.pop();

            ans.push_back(fr);

            for(int i : adj[fr]) {

                indegree[i]--;

                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if(ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};