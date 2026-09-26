class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kn;

        for(auto i: knowledge){
            kn[i[0]] = i[1];
        }

        string result;
        queue<char> st;
        for(char i: s){
            if((i=='(' || st.size()>0) && i!=')'){
                st.push(i);
            }else if(i==')'){
                string val;
                st.pop();
                while(st.size()>0){
                    val+=st.front();
                    st.pop();
                }

                // cout<<val<<endl;

                if(kn.contains(val)){
                    result+=kn[val];
                }else{
                    result+='?';
                }
            }else{
                result+=i;
            }
        }

        return result;
    }
};