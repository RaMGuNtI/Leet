class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isEven = true;
        bool isOdd = true;
        
        priority_queue<int, vector<int>, greater<int>> evp;
        priority_queue<int, vector<int>, greater<int>> odp;

        for(int i: nums1){
            if(i%2==0){
                isOdd = false;
                evp.push(i);
            }
        }

        for(int i: nums1){
            if(i%2!=0){
                isEven = false;
                odp.push(i);
            }
        }

        if(isOdd || isEven) return true;

        while(!odp.empty() && !evp.empty()){
            if(evp.top()>odp.top()) evp.pop();
            else{
                while(!odp.empty() && odp.top()>=evp.top()){
                    odp.pop();
                }
            }
        }

        return evp.empty();
    }
};