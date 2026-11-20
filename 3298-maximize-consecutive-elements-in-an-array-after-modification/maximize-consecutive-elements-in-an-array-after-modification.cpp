class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int findVal(vector<int>& nums, int st, int target){
        auto it = lower_bound(nums.begin() + st, nums.end(), target);

        if(it==nums.end()){
            return -1;
        }
        
        if(*it!=target) return -1;

        return it - nums.begin();
    }

    int solve(int idx, int inc, vector<int>& nums){
        if(dp[idx][inc]!=-1) return dp[idx][inc];
        int currVal = nums[idx] + inc;

        int len = 1;
        int j = findVal(nums, idx+1, currVal+1);
        if(j!=-1){
            len = max(len, 1 + solve(j, 0, nums));
        }

        j = findVal(nums, idx+1, currVal);
        if(j!=-1){
            len = max(len, 1 + solve(j, 1, nums));
        }

        return dp[idx][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(2, -1));
        sort(nums.begin(), nums.end());

        int res = 1;
        for(int i=0; i<n; i++){
            res = max({res, solve(i, 0, nums), solve(i, 1, nums)});
        }    

        return res;
    }
};