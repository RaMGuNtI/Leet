class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        const int n = nums.size();


        if(tsum == x) return n;
        int target = tsum - x;

        int i = 0, j = 0, sum = 0, mx = 0;

        while (j < n) { 
            sum += nums[j];

            if (sum == target){
                mx = max(mx, j - i + 1);
                j++;

            } else if(sum > target) {
                while (i <= j and sum > target) {
                    sum -= nums[i];
                    i++;
                }

              
                if (sum == target) mx = max(mx, j - i + 1);
                 j++;

            } else {
                j++;
            }
        }
        cout << mx << endl;

        int res = n - mx;
        return (mx == 0 ? -1 : res);
    }
};