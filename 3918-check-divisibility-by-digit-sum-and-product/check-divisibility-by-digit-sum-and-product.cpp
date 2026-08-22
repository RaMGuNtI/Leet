class Solution {
public:
    bool checkDivisibility(int n) {
        long long s = 0;
        long long p = 1;
        int org = n;
        while(n){
            int las = n%10;
            n/=10;
            s+=las;
            p*=las;
        }
        return org%(s+p)==0;
    }
};