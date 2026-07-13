class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0, l = 0, r = n-1, ans = 0;

        while(l<r){
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax<rightMax){
                ans+=leftMax - height[l];
                l++;
            }else{
                ans+=rightMax - height[r];
                r--;
            }
        }

        return ans;
    }
};