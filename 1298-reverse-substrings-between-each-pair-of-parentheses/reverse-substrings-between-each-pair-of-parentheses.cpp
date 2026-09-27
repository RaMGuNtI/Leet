class Solution {
public:
    string reverseParentheses(string s) {
        vector<stack<char>> pwords;
        int bal = -1;
        string result = "";
        for(char i: s){
            if('('==i){
                bal++;
                stack<char> st;
                pwords.push_back(st);
            }else if(')'==i){
                if(bal>0){
                    stack<char> &prev = pwords[bal-1];
                    stack<char> &curr = pwords[bal];

                    while(!curr.empty()){
                        prev.push(curr.top());
                        curr.pop();
                    }
                }else{
                    string midPart = "";
                    stack<char> &curr = pwords[bal];

                    while(!curr.empty()){
                        midPart+=curr.top();
                        curr.pop();
                    }
                    result+=midPart;
                }
                bal--;
            }else if(bal!=-1){
                pwords[bal].push(i);
            }else{
                result+=i;
            }
        }

        return result;
    }
};