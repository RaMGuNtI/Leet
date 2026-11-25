
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        if(m == 0) return 0;
        if(m > n) return -1;

        int mod = 101;
        int base = 26;

        int nHashVal = 0;
        int winHashVal = 0;
        int highestPow = 1;

        for(int i = 0; i < m - 1; i++) {
            highestPow = (highestPow * base) % mod;
        }

        for(int i = 0; i < m; i++) {
            nHashVal = (nHashVal * base + needle[i]) % mod;
            winHashVal = (winHashVal * base + haystack[i]) % mod;
        }

        for(int i = 0; i <= n - m; i++) {

            if(winHashVal == nHashVal) {
                if(haystack.substr(i, m) == needle) {
                    return i;
                }
            }

            if(i < n - m) {
                winHashVal = (
                    (winHashVal - haystack[i] * highestPow) * base
                    + haystack[i + m]
                ) % mod;

                if(winHashVal < 0) {
                    winHashVal += mod;
                }
            }
        }

        return -1;
    }
};
