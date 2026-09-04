class Solution {
public:
    int firstStableIndex(vector<int>& n, int k) {
        int ans = 0;
        int s = n.size();
        vector<int> rm(s, 0);
        vector<int> lm(s, 0);
        rm[0] = n[0];
        lm[s-1] = n[s-1];
        for(int i = 1; i < s; i++){
            rm[i] = max(rm[i-1], n[i]);
        }

        for(int i = s-2; i>=0; i--){
            lm[i] = min(lm[i+1], n[i]);
        }

        for(int i = 0; i < s; i++){
            if (rm[i] - lm[i] <= k){
                return i;
            }
        }
        return -1;
    }
};