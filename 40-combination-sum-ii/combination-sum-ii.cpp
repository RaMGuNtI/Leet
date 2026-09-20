class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> temp, int target, vector<int> &arr, int idz){
        if(target<0 || idz>=arr.size()){
            if(target==0){
                ans.push_back(temp);
            }

            return;
        }

        temp.push_back(arr[idz]);
        helper(ans, temp, target-arr[idz], arr, idz+1);
        temp.pop_back();
        while(idz+1<arr.size() && arr[idz]==arr[idz+1]) idz++;
        helper(ans, temp, target, arr, idz+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;

        helper(ans, {}, target, candidates, 0);
        return ans;
    }
};