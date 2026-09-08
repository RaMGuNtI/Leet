class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        
        int leftMax = 0;
        int rightMax = 0;
        int lit = 0;
        while(left<right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            lit = max(lit, min(leftMax, rightMax)*(right-left));
            if(leftMax<rightMax){
                left++;
            }else{
                right--;
            }
        }

        return lit;
    }
};