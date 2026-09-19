class Solution {
public:
    void helper(vector<string> &ans, string temp, int n, int reqCloseBrac, int len, int currNeeded){
        if(len==n*2){
            ans.push_back(temp);
            return;
        }
        
        if(temp.back()=='('){
            if(currNeeded>0){
                helper(ans, temp+')', n, reqCloseBrac, len+1, currNeeded-1);
            }
            if(reqCloseBrac<n){
                helper(ans, temp+'(', n, reqCloseBrac+1, len+1, currNeeded+1);
            }
        }else{
            if(reqCloseBrac<n){
                helper(ans, temp+'(', n, reqCloseBrac+1, len+1, currNeeded+1);
            }
            if(currNeeded>0){
                helper(ans, temp+')', n, reqCloseBrac, len+1, currNeeded-1);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        helper(ans, "(", n, 1, 1, 1);
        
        return ans;
    }
};