class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n,-1);
        vector<int> sufMax(n,-1);

        for(int i=0; i<n; i++){
            if(i>0){
                preMax[i] = max(preMax[i-1], height[i]);
            }else{
                preMax[i] = height[i];
            }
        }
        
        for(int i=n-1; i>=0; i--){
            if(i<n-1){
                sufMax[i] = max(sufMax[i+1], height[i]);
            }else{
                sufMax[i] = height[i];
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(height[i]<preMax[i] && height[i]<sufMax[i]){
                ans += min(preMax[i], sufMax[i]) - height[i];
            }
        }
        return ans;
    }
};