class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;

        for(char ch: s){
            freq[ch]++;
        }
        int n = s.size();

        vector<int> ff(n+1, 0);
        for(auto &[a, b]: freq){
            ff[b]++;
        }

        priority_queue<int> pq;

        for(int i=n; i>0; i--){
            if(ff[i]==0){
                pq.push(i);
            }
        }

        int res = 0;
        for(int i=n; i>0; i--){
            while(ff[i]>1){
                while(!pq.empty() && pq.top()>i) pq.pop();

                if(pq.empty()){
                    res+=i;
                }else{
                    res+=(i-pq.top());
                    pq.pop();
                }
                ff[i]--;
            }
        }

        return res;
    }
};