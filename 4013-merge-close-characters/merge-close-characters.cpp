class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char, int> mp;
        int skip = 0;
        string ans;
        for(int i=0; i<s.size(); i++){
            if(mp.contains(s[i])){
                if(i-skip-mp[s[i]]<=k){
                    skip++;
                    continue;
                }else{
                    mp[s[i]] = i-skip;
                }
            }else{
                mp[s[i]] = i - skip;
            }

            ans+=s[i];
        }

        return ans;
    }
};