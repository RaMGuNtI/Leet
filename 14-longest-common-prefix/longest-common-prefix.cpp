class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int min_len = INT_MAX;

        for(string s: strs){
            min_len = min(min_len, (int)s.size());
        }

        int i = 0;
        while(i<min_len){
            char exp = strs[0][i];

            bool fa = false;
            for(int j=1; j<n; j++){
                if(exp!=strs[j][i]){
                    fa = true;
                    break;
                }
            }

            if(fa) break;
            i++;
        }

        return strs[0].substr(0, i);
    }
};