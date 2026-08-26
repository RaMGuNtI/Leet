class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int currSatis = 0, n = customers.size();
        for(int i=0; i<n; i++){
            if(grumpy[i]==0) currSatis+=customers[i];
        }

        int addUp = 0;
        int temp = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i]==1) temp+=customers[i];

            if(i>=minutes){
                int lef = i-minutes;
                if(grumpy[lef]==1) temp-=customers[lef];
            }

            addUp = max(addUp, temp);
        }

        return currSatis+addUp;
    }
};