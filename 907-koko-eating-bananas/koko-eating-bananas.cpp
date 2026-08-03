class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while (low<=high){
            int mid = (low+high)/2;
            long long mal=0;
            for (auto i:piles){
                if (i%mid==0){
                    mal+=i/mid;
                }
                else{
                    mal+=(i/mid)+1;
                }
            }
            if (mal<=h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return (ans);
    }
};