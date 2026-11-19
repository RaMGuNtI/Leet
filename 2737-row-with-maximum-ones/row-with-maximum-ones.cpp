class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> mini = {-1, -1};
        int cnt = 0;
        for(auto e: mat){
            int sum = accumulate(e.begin(), e.end(), 0);
            if(sum>mini[1]){
                mini = {cnt, sum};
            }
            cnt++;
        }

        return mini;
    }
};