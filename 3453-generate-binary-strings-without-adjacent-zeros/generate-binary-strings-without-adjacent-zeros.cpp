class Solution {
public:
    void helper(vector<string> &ans, string temp, int n, int len){
        if(n==len){
            ans.push_back(temp);
            return;
        }

        if(temp.back()=='1'){
            helper(ans, temp+'0', n, len+1);
            helper(ans, temp+'1', n, len+1);
        }else{
            helper(ans, temp+'1', n, len+1);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(ans, "1", n, 1);
        helper(ans, "0", n, 1);

        return ans;
    }
};