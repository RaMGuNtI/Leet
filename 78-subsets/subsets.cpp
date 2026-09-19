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
        addSub(ans, temp, idx+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        addSub(ans, {}, 0, nums);

        return ans;
    }
};