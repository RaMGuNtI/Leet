class Solution {
public:
    vector<vector<int>> dp;
    int cheapestPrice = INT_MAX;

    int solve(int n, int budget, vector<int> &copies, vector<vector<int>>& items){
        if(n==0){
            return budget/cheapestPrice;
        }

        if(dp[n][budget]!=-1) return dp[n][budget];
        int take = 0;
        int skip = 0;
        
        int price = items[n-1][1];
        if(price<=budget){
            take = 1 + copies[n-1] + solve(n-1, budget - price, copies, items);
        }

        skip = solve(n-1, budget, copies, items);

        return dp[n][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> copies;
        int n = items.size();
        dp.assign(n+1, vector<int>(budget+1, -1));

        for(int i=0; i<n; i++){
            int copy = 0;
            cheapestPrice = min(cheapestPrice, items[i][1]);

            int f1 = items[i][0];
            for(int j=0; j<n; j++){
                if(i==j) continue;

                if(items[j][0]%f1==0) copy++;
            }

            copies.push_back(copy);
        }

        return solve(n, budget, copies, items);
    }
};