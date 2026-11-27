
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> copies;
        int n = items.size();

        int cheapestPrice = INT_MAX;

        for(int i=0; i<n; i++){
            int copy = 0;
            cheapestPrice = min(cheapestPrice, items[i][1]);

            int f1 = items[i][0];

            for(int j=0; j<n; j++){
                if(i==j) continue;

                if(items[j][0] % f1 == 0)
                    copy++;
            }

            copies.push_back(copy);
        }

        vector<vector<int>> dp(n+1, vector<int>(budget+1, 0));

        for(int currBudget = 0; currBudget <= budget; currBudget++){
            dp[0][currBudget] = currBudget / cheapestPrice;
        }

        for(int i=1; i<=n; i++){
            int price = items[i-1][1];

            for(int j=0; j<=budget; j++){
                int take = 0;
                int skip = dp[i-1][j];

                if(price <= j){
                    take = 1 + copies[i-1] + dp[i-1][j-price];
                }

                dp[i][j] = max(take, skip);
            }
        }

        return dp[n][budget];
    }
};
