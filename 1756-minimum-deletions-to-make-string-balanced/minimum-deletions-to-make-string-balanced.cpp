class Solution {
public:
    int minimumDeletions(string s) {
        int as = 0, bs = 0;
        int n = s.size();
        if(n<=1) return 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a') as++;
        }

        int res = INT_MAX;
        for(int i=0; i<n; i++){
            if(s[i]=='a') as--;
            res = min(res, as+bs);
            if(s[i]=='b') bs++;
        }

        return res;
    }
};