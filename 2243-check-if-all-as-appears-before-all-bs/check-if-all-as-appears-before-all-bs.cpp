class Solution {
public:
    bool checkString(string s) {
        bool fb = false;

        for(char ch: s){
            if(ch=='b') fb = true;
            else if(fb) return false;
        }

        return true;
    }
};