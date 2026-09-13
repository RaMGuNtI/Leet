class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> p1;
        vector<pair<int, int>> p2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1){
                    p1.push_back({i, j});
                }

                if(img2[i][j]==1){
                    p2.push_back({i, j});
                }
            }
        }

        map<pair<int, int>, vector<pair<int, int>>> mp;
        for(auto i: p1){
            for(auto j:p2){
                mp[i].push_back({i.first-j.first, i.second-j.second});
            }
        }

        map<pair<int, int>, int> freq;
        for(auto &[a, b]: mp){
            for(auto j: b){
                freq[j]++;
            }
        }

        int ans = 0;
        for(auto &[a,b]: freq){
            ans = max(ans, b);
        }

        return ans;
    }
};