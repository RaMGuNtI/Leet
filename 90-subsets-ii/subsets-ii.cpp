class Solution {
public:
    void addSub(vector<vector<int>> &ans, vector<int> temp, int idx, vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(temp);    
            return;
        }
        
        temp.push_back(nums[idx]);
        addSub(ans, temp, idx+1, nums);
        temp.pop_back();    
        while(idx<nums.size()-1 && nums[idx]==nums[idx+1]) idx++;
        addSub(ans, temp, idx+1, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        addSub(ans, {}, 0, nums);

        return ans;    
    }
};