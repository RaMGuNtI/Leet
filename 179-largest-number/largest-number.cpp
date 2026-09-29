class Solution {
public:
    static bool check(string &a, string &b){
        return (a+b) > (b+a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> ins;

        for(int i: nums){
            ins.push_back(to_string(i));
        }

        sort(ins.begin(), ins.end(), check);
        string result = "";
        if(ins[0]=="0") return "0";
        for(string i: ins){
            result+=i;
        }

        return result;
    }
};