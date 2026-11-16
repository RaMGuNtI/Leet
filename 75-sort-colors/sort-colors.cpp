class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for(int i: nums){
            if(i==0) zeros++;
            else if(i==1) ones++;
            else twos++;
        }

        int idx = 0;
        while(zeros){
            nums[idx] = 0;
            zeros--;
            idx++;
        }
        while(ones){
            nums[idx] = 1;
            ones--;
            idx++;
        }
        while(twos){
            nums[idx] = 2;
            twos--;
            idx++;
        }
    }
};