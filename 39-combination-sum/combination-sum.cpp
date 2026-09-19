class Solution {
public:
    void helper(int idx, vector<int>& candidates, int target, int n, set<vector<int>> &ans, vector<int> temp){
        if(idx==n || target<0) return;
        if(target==0){
            ans.insert(temp);
            return;
        }

        temp.push_back(candidates[idx]);
        helper(idx+1, candidates, target-candidates[idx], n, ans, temp);
        helper(idx, candidates, target-candidates[idx], n, ans, temp);
        temp.pop_back();
        helper(idx+1, candidates, target, n, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;

        helper(0, candidates, target, candidates.size(), ans, {});
        vector<vector<int>> ep;
        for(auto i: ans){
            ep.push_back(i);
        }

        return ep;
    }
};