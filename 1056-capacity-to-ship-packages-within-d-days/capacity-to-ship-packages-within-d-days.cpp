class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = *max_element(weights.begin(), weights.end());
        int maxi = accumulate(weights.begin(), weights.end(), 0);
        int n = weights.size();
        int ans=-1;
        while(mini<=maxi){
            int mid = (mini+maxi)/2;

            int sumo = 0;
            int daysSpent = 1;
            for(int i=0; i<n; i++){
                if(sumo+weights[i]<=mid){
                    sumo+=weights[i];
                }else{
                    daysSpent+=1;
                    sumo=weights[i];
                }
            }
            // daysSpent+=1;
            // if(daysSpent==days) return mid;

            if(daysSpent<=days){
                ans=mid;
                maxi = mid-1;
            }else{
                mini = mid + 1;
            }
        }

        return ans;
    }
};