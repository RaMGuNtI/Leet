class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        if(n<=2) return stoi(s);
        long long num = 0, sign = 1, ans = 0;

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(isdigit(ch)){
                num=num*10 + (ch-'0');
            }else if(ch=='+'){
                ans += sign*num;
                num = 0;
                sign = 1;
            }else if(ch=='-'){
                ans+=sign*num;
                num = 0;
                sign = -1;
            }else if(ch=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                num = 0;
                sign = 1;
            }else if(ch==')'){
                ans+=sign*num;
                num = 0;
                ans*=st.top();
                st.pop();
                ans+=st.top();
                st.pop();
            }
        }
        ans+=sign*num;

        return ans;
    }
};