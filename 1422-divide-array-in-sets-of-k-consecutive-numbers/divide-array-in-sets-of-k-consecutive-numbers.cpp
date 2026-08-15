class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0) return false;
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        
        for(int i: nums) mp[i]++;
        
        for(int i: nums){
            if(mp[i]==0) continue;
            int c = 1;
            mp[i]--;
            while(c<k){
                if(mp[i+c]>0){
                     mp[i+c]--;
                     c++;
                }
                else return false;
            }
        }
        
        return true;
    }
};