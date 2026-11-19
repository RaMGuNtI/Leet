class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        for(auto& e: grid){
            auto it = lower_bound(e.begin(), e.end(), target);
            if(it==e.end()) continue;
            if(*it==target) return true;
        }    
        
        return false;
    }
};