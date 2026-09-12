class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                revGraph[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int next : revGraph[node]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};