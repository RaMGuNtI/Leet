class Solution {
public:
    int mirrorFrequency(string s) {
        priority_queue<int, vector<int>, greater<int>> ipq;
        priority_queue<char, vector<char>, greater<char>> cpq;

        for(auto i: s){
            if(isalpha(i)) cpq.push(i);
            if(isdigit(i)) ipq.push(i);
        }

        string numSt = "";
        string chSt = "";
        while(!ipq.empty()){
            numSt+=ipq.top();
            ipq.pop();
        }

        while(!cpq.empty()){
            chSt+=cpq.top();
            cpq.pop();
        }

        int ans = 0;
        int i=0, j = numSt.size()-1;
        while(i<=j){
            char lefVal = '9'-(numSt[i]-'0');
            char rigVal = numSt[j];

            if(lefVal==rigVal){
                i++;
                j--;
            }else if(lefVal<rigVal){
                j--;
                ans++;
            }else{
                i++;
                ans++;
            }
        }

        i=0, j = chSt.size()-1;
        while(i<=j){
            char lefVal = 'z'-(chSt[i]-'a');
            char rigVal = chSt[j];

            if(lefVal==rigVal){
                i++;
                j--;
            }else if(lefVal<rigVal){
                j--;
                ans++;
            }else{
                i++;
                ans++;
            }
        }

        return ans;
    }
};