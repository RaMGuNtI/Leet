class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<int> res;
        for(auto &[a, b]: mp){
            if(b>n/3){
                res.push_back(a);
            }
        }

        return res;
    }
};