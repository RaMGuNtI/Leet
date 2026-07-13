class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> dup = positions;
        unordered_map<int, pair<int, char>> mp;
        int n = positions.size();

        for (int i = 0; i < n; i++) {
            mp[positions[i]] = {healths[i], directions[i]};
        }

        sort(positions.begin(), positions.end());

        stack<int> st;

        for (int i = 0; i < n; i++) {
            bool dead = false;

            while (!st.empty() &&
                   mp[st.top()].second == 'R' &&
                   mp[positions[i]].second == 'L') {

                if (mp[st.top()].first < mp[positions[i]].first) {
                    mp[st.top()].first = 0;      
                    st.pop();
                    mp[positions[i]].first--;
                }
                else if (mp[st.top()].first > mp[positions[i]].first) {
                    mp[positions[i]].first = 0;  
                    mp[st.top()].first--;
                    dead = true;
                    break;
                }
                else {
                    mp[st.top()].first = 0;      
                    mp[positions[i]].first = 0;
                    st.pop();
                    dead = true;
                    break;
                }
            }

            if (!dead && mp[positions[i]].first > 0) {
                st.push(positions[i]);
            }
        }

        vector<int> ans;

        for (int pos : dup) {
            if (mp[pos].first > 0) {
                ans.push_back(mp[pos].first);
            }
        }

        return ans;
    }
};