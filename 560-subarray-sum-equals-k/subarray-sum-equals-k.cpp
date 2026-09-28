class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int n = nums.size();
        
        int sm = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            sm+=nums[i];

            if(mp.contains(sm-k)){
                count+=mp[sm-k];
            }

            mp[sm]++;
        }

        return count;
    }
};