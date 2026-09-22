class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1;
        int n = arr.size();
        int start = 0;
        int i=0;
        for(i; i<n-1; i++){
            if(i%2!=0 && arr[i]<arr[i+1]){
                continue;
            }else if(i%2==0 && arr[i]>arr[i+1]){
                continue;
            }else{
                ans = max(ans, i-start+1);
                start = i+1;
            }
        }
        ans = max(ans, i-start+1);

        start = 0;
        i=0;
        for(i; i<n-1; i++){
            if(i%2!=0 && arr[i]>arr[i+1]){
                continue;
            }else if(i%2==0 && arr[i]<arr[i+1]){
                continue;
            }else{
                ans = max(ans, i-start+1);
                start = i+1;
            }
        }
        ans = max(ans, i-start+1);

        return ans;
    }
};