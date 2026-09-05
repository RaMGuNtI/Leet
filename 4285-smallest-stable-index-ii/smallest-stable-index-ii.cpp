class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMax = nums[0];

        vector<int> suffix(n);
        
        suffix[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            suffix[j] = min(nums[j], suffix[j + 1]);
        }

        for (int j = 0; j < n; j++) {
            prefixMax = max(prefixMax, nums[j]);

            if (prefixMax - suffix[j] <= k)
                return j;
        }

        return -1;
    }
};