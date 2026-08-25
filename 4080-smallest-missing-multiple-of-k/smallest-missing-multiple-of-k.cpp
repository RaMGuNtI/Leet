class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int need=k;
        for(int num:nums){
            if(num%k!=0){
                continue;
            }
            if(num==need){
                need+=k;
            }
        }
        return need;
    }
};