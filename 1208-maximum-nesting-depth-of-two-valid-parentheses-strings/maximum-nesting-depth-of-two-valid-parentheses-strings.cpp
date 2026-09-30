class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result;
        int req1 = 0, req2 = 0;
        
        for(char i: seq){
            if(i=='('){
                if(req1<=req2){
                    req1++;
                    result.push_back(0);
                }else{
                    req2++;
                    result.push_back(1);
                }
            }else{
                if(req1>=req2){
                    req1--;
                    result.push_back(0);
                }else{
                    req2--;
                    result.push_back(1);
                }
            }
        }

        return result;
    }
};