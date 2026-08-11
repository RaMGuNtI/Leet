class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums) mp[i]++;

        int prefixSum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]+1==nums[i]) prefixSum+=nums[i];
            else break;
        }


        while(mp.contains(prefixSum)) prefixSum++;

        return prefixSum;
    }
};