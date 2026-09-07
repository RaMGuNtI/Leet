class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int currWaterCap = capacity;
        int n = plants.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            if(currWaterCap>=plants[i]){
                currWaterCap-=plants[i];
                ans++;
            }else{
                ans+=(i)*2 + 1;
                currWaterCap = capacity;
                currWaterCap-=plants[i];
            }
        }

        return ans;
    }
};