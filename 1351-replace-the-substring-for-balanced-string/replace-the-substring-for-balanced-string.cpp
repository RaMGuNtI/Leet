class Solution {
public:
    bool isSatis(unordered_map<char, int> req, unordered_map<char, int> win){
        for(auto &[a,b]:req){
            if(b>win[a]) return false;
        }

        return true;
    }


    int balancedString(string s) {
        unordered_map<char, int> mp={{'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        int n = s.size();

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        unordered_map<char, int> req;
        int each = n/4;
        for(auto &[a, b]:mp){
            if(b>(each)) req[a] = b-each;
        }
        if(req.size()==0) return 0;

        unordered_map<char, int> win;
        bool satis = false;

        int left = 0;
        int ans = INT_MAX;
        for(int right = 0; right<n; right++){
            if(req.contains(s[right])){
                win[s[right]]++;
                if(!satis){
                    satis = isSatis(req, win);
                }
            }

            if(satis){
                while(left<right){
                    char curr = s[left];
                    if(!req.contains(curr)) left++;
                    else if(win[curr]>req[curr]){
                        win[curr]--;
                        left++;
                    }
                    else{
                        break;
                    }
                }
                ans = min(ans, right-left+1);
            }
        }

        return ans;
    }
};