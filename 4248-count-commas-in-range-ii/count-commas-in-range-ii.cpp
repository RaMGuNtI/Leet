class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans = 0;
        if(n>=pow(10, 3) && n<pow(10, 6)){
            return (n-1000)+1;
        }

        if(n>=pow(10, 6) && n<pow(10, 9)){
            return (n-pow(10, 6))*2 + (pow(10, 6)-pow(10, 3)) + 2;
        }

        if(n>=pow(10, 9) && n<pow(10, 12)){
            return (n-pow(10, 9))*3 +(pow(10, 9)-pow(10, 6))*2 + (pow(10, 6)-pow(10, 3)) + 3;
        }

        if(n>=pow(10, 12) && n<pow(10, 15)){
            return (n-pow(10, 12))*4 + (pow(10, 12)-pow(10, 9))*3 +(pow(10, 9)-pow(10, 6))*2 + (pow(10, 6)-pow(10, 3)) + 4;
        }

        
        return (pow(10, 15)-pow(10, 12))*4 + (pow(10, 12)-pow(10, 9))*3 +(pow(10, 9)-pow(10, 6))*2 + (pow(10, 6)-pow(10, 3)) + 5;
    }
};