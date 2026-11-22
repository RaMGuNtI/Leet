class Solution {
public:
    typedef long long int;
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges,
                                              vector<int>& requiredSignals) {
        unordered_map<int, vector<pair<int, long long>>> mp;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        for (auto v : edges) {
            mp[v[0]].push_back({v[1], v[2]});
        }

        vector<long long> res(n, -1);
        res[0] = 0;

        for (auto i : mp[0]) {
            pq.push({i.second, i.first});
        }

        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();

            long long time = tp.first;
            int node = tp.second;
            if (res[node] != -1)
                continue;

            requiredSignals[node]--;
            if (requiredSignals[node] == 0) {
                res[node] = time;

                for (auto i : mp[node]) {
                    pq.push({i.second + time, i.first});
                }
            }
        }

        return res;
    }
};
