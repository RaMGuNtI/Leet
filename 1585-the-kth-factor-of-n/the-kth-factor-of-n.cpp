class Solution {
public:
    int kthFactor(int n, int k) {
        int skip = 1;
        if(n%2!=0) skip++;

        for(int i=1; i<=n; i+=skip){
            if(n%i==0) k--;
            if(k==0) return i;
        }

        return -1;
    }
};