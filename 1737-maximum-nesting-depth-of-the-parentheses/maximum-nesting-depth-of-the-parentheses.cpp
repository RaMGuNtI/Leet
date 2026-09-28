class Solution {
public:
    int maxDepth(string s) {
        int op = 0;
        int ans = 0;
        for(char i: s){
            if(i=='('){
                op++;
                ans = max(op, ans);
            }else if(i==')'){
                op--;
            }
        }    

        return ans;
    }
};