class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int ,int>>> ppq;
        priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int ,int>>> npq;

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0) npq.push({i, nums[i]});
            else ppq.push({i, nums[i]});
        }

        for(int i=0; i<n; i+=2){
            nums[i] = ppq.top().second;
            ppq.pop();
            nums[i+1] = npq.top().second;
            npq.pop();
        }

        return nums;
    }
};