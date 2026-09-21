class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int add = 0;
        for(int i: nums){
            add+=i;
            ans = max(add, ans);
            if(add<0) add = 0;
        }

        return ans;
    }
};