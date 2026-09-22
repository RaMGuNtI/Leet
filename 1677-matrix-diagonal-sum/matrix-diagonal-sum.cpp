class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i=0; i<n; i++){
            ans+=mat[i][i];
        }

        for(int i=0; i<n; i++){
            ans+=mat[i][n-i-1];
        }

        if(n%2==0){
            return ans;
        }
        
        return ans-mat[n/2][n/2];
    }
};