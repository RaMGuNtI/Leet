class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        
        for(int i: hand) mp[i]++;
        
        for(int i: hand){
            if(mp[i]==0) continue;
            int c = 1;
            mp[i]--;
            while(c<groupSize){
                if(mp[i+c]>0){
                     mp[i+c]--;
                     c++;
                }
                else return false;
            }
        }
        // for(auto &[a, b]:mp) if(b!=0) return false;
        
        return true;
    }
};