class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        
        pref[0] = nums[0];

        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+nums[i];
        }

        int mi = *min_element(pref.begin(), pref.end());

        if(mi<0){
            return -mi+1;
        }else{
            return 1;
        }
    }
};