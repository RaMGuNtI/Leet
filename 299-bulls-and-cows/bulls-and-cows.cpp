class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        
        for(char ch: secret) mp[ch]++;

        int b = 0, c = 0;
        for(int i=0; i<secret.size(); i++){
            if(secret[i]==guess[i]){
                b++;
                if(mp[guess[i]]<=0) c--;
            }
            else{
                if(mp[guess[i]]>0){
                    c++;
                }
            }
            mp[guess[i]]--;
        }

        string s = to_string(b)+'A'+to_string(c)+'B';

        return s;
    }
};