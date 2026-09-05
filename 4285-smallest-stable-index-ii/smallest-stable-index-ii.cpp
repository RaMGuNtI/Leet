class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return 0;
        vector<int> mge(n, -1);
        vector<int> sge(n, -1);

        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(maxi==INT_MIN){
                maxi = nums[i];
            }
            maxi = max(nums[i], maxi);
            mge[i] = maxi;
        }

        int mini = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(mini==INT_MAX){
                mini = nums[i];
            }
            mini = min(nums[i], mini);
            sge[i] = mini;
        }

        for(int i=0; i<n; i++){
            if(mge[i]-sge[i]<=k) return i;
        }

        return -1;
    }
};