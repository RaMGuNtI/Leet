class Solution {
public:
    bool isPrime(int num){
        if(num < 2) return false;
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;

        for(int i = 2; i <= n / 2; i++){
            if(isPrime(i) && isPrime(n - i)){
                ans.push_back({i, n - i});
            }
        }

        return ans;
    }
};