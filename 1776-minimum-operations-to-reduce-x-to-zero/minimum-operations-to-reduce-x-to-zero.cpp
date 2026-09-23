class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();

        vector<int> pre(n), suff(n);

        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + nums[i];
        }

        suff[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suff[i] = suff[i + 1] + nums[i];
        }

        int mini = INT_MAX;
        for (int i = 0; i < n; i++){
            if (pre[i] == x) mini = min(mini, i + 1);
            if (suff[i] == x) mini = min(mini, n - i);
        }


        for (int i = n - 1; i >= 0; i--){
            int diff = x - suff[i];
            auto lb = lower_bound(pre.begin(), pre.end(), diff) - pre.begin();

            if (lb < n and pre[lb] == diff and lb < i){
                mini = min(mini, (n - i) + (int)(lb + 1));
            }
        }

        return (mini == INT_MAX ? -1 : mini);
    }
};