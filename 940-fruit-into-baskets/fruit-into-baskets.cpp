class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;

        int n = fruits.size();
        int lef = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            mp[fruits[i]]++;

            while (mp.size() > 2) {
                mp[fruits[lef]]--;

                if (mp[fruits[lef]] == 0) {
                    mp.erase(fruits[lef]);
                }

                lef++;
            }

            ans = max(ans, i - lef + 1);
        }

        return ans;
    }
};