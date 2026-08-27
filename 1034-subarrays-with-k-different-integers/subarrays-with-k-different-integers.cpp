class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> win;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {
            win[nums[right]]++;

            while(win.size() > k) {
                win[nums[left]]--;

                if(win[nums[left]] == 0) {
                    win.erase(nums[left]);
                }

                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};