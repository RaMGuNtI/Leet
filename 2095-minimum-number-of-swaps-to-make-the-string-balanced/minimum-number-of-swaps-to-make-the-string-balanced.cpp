class Solution {
public:
    int minSwaps(string s) {
        int b = 0;
        int m = 0;

        for(char i: s){
            if(i==']'){
                b+=1;
                m = max(b, m);
            }else{
                b-=1;
            }
        }
        return (m+1)/2;
    }
};