class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int firSum = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int lef = k-1;
        int rig = cardPoints.size()-1;
        int ans = firSum;
        while(lef>=0){
            firSum-=cardPoints[lef--];
            firSum+=cardPoints[rig--];
            ans = max(ans, firSum);
        }

        return ans;
    }
};