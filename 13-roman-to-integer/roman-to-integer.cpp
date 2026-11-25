class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        unordered_map<char, int> mapp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int num = 0;
        for(int i=0; i<n; i++){
            int curr = mapp[s[i]];
            int next = 0;
            if(i+1<n){
                next = mapp[s[i+1]];
            }

            if(curr<next){
                num = num + next - curr;
                i++;
            }else{
                num = num + curr;
            }
        }

        return num;
    }
};