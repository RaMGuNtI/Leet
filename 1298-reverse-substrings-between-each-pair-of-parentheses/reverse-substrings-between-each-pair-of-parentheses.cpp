class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> st;
        string result;

        for (char c : s) {
            if (c == '(') {
                st.push_back("");
            }
            else if (c == ')') {
                reverse(st.back().begin(), st.back().end());

                string curr = st.back();
                st.pop_back();

                if (st.empty())
                    result += curr;
                else
                    st.back() += curr;
            }
            else {
                if (st.empty())
                    result += c;
                else
                    st.back() += c;
            }
        }

        return result;
    }
};