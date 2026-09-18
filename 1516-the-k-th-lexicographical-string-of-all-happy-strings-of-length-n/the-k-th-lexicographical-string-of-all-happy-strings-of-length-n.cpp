class Solution {
public:
    void helper(vector<string> &poss, string temp, int n, int len){
        if(n==len){
            poss.push_back(temp);
            return;
        }

        if(temp.back()=='a'){
            helper(poss, temp+'b', n, len+1);
            helper(poss, temp+'c', n, len+1);
        }else if(temp.back()=='b'){
            helper(poss, temp+'a', n, len+1);
            helper(poss, temp+'c', n, len+1);
        }else{
            helper(poss, temp+'b', n, len+1);
            helper(poss, temp+'a', n, len+1);
        }
    }


    string getHappyString(int n, int k) {
        vector<string> poss;
        helper(poss, "a", n, 1);
        helper(poss, "b", n, 1);
        helper(poss, "c", n, 1);

        sort(poss.begin(), poss.end());
        if(poss.size()<k) return "";
        return poss[k-1];
    }
};