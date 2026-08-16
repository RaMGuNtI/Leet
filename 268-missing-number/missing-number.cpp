class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int su = accumulate(nums.begin(), nums.end(), 0);

        int ac = n * (n + 1) / 2;

        return ac - su;
    }
};