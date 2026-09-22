class Solution {
public:
    bool isPalin(string s){
        int i = 0;
        int j = s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void helper(vector<vector<string>> &ans, vector<string> temp, string s){
        if(s.size()==0){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<s.size(); i++){
            if(isPalin(s.substr(0, i+1))){
                temp.push_back(s.substr(0, i+1));
                helper(ans, temp, s.substr(i+1));
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        helper(ans, {}, s);

        return ans;
    }
};