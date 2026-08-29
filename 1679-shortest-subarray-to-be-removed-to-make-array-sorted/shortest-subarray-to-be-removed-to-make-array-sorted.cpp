class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int res = INT_MAX;
        int r = n-1;
        while(r>0 && arr[r-1]<=arr[r]){
            r--;
        }
        res = min(res, r);
        int l = 0;
        while(l<r){
            while(r<n && arr[l]>arr[r]){
                r++;
            }
            res = min(res, r-l-1);
            if(arr[l]>arr[l+1]) break;
            l++;
        }

        return res;
    }
};