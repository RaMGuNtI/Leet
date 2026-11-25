class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int start = 1, end = n;
        int res = n;

        const long long BASE = 10;
        const long long MOD = 1000000007;

        while (start <= end) {
            int k = (start + end) / 2;

            unordered_map<long long, int> mp;

            long long winHash = 0;
            long long power = 1;

            for (int i = 1; i < k; i++) {
                power = (power * BASE) % MOD;
            }

            for (int i = 0; i < k; i++) {
                winHash = (winHash * BASE + nums[i]) % MOD;
            }

            mp[winHash]++;

            for (int i = k; i < n; i++) {
                winHash = (winHash - nums[i-k] * power % MOD + MOD) % MOD;

                winHash = (winHash * BASE + nums[i]) % MOD;

                mp[winHash]++;
            }

            bool found = false;

            for (auto &[hash, freq] : mp) {
                if (freq == 1) {
                    found = true;
                    break;
                }
            }

            if (found) {
                res = k;
                end = k - 1;
            } else {
                start = k + 1;
            }
        }

        return res;
    }
};