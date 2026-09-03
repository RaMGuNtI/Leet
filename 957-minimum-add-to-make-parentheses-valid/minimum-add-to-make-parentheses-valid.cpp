class Solution {
public:
    int minAddToMakeValid(string s) {
        int b = 0;
        int m = 0;
        for(char i: s){
            if(i==')'){
                b-=1;
                m = min(b, m);
            }else{
                b+=1;
            }
        }

        return -m*2 + b ;
    }
};