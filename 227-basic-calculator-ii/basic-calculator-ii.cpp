class Solution {
public:
    int calculate(string s) {
        long long ans = 0;
        long long last = 0;
        long long num = 0;
        char op = '+';

        s += '+';   

        for (char ch : s) {
            if (ch == ' ') continue;

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else {
                if (op == '+') {
                    ans += last;
                    last = num;
                } else if (op == '-') {
                    ans += last;
                    last = -num;
                } else if (op == '*') {
                    last *= num;
                } else if (op == '/') {
                    last /= num;
                }

                op = ch;
                num = 0;
            }
        }

        return ans + last;
    }
};