class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        int i = n-1;
        for(i; i>=0; i--){
            int a = num[i] - '0';

            if(a%2!=0){
                break;
            }
        }

        return num.substr(0, i+1);
    }
};