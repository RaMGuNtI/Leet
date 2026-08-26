class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if(n<k) return 0;

        int left = 0;
        int right = k-1;
        int iniSum = accumulate(arr.begin(), arr.begin()+k, 0);
        int ans = 0;
        if(iniSum/k>=threshold) ans++;
        right++;
        for(right; right<n; right++){
            iniSum-=arr[left++];
            iniSum+=arr[right];

            if(iniSum/k>=threshold) ans++;
        }

        return ans;
    }
};