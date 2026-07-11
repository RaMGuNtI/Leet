class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i=0; i<n; i++){
            string op = tokens[i];
            if(op=="*" || op=="+" || op=="-" || op=="/"){
                int sec = st.top();
                st.pop();
                int fir = st.top();
                st.pop();

                int result = 0;
                if(op=="+"){
                    result = fir + sec;
                }else if(op=="-"){
                    result = fir - sec;
                }else if(op=="*"){
                    result = fir * sec;
                }else{
                    result = fir/sec;
                }
                st.push(result);
            }else{
                st.push(stoi(op));
            }
        }

        return st.top();
    }
};