class Solution {
public:
    int quick_select(vector<int> arr, int k){
        vector<int> left;
        vector<int> right;
        vector<int> mid;
        
        int pivot = arr[rand()%arr.size()];
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>pivot) left.push_back(arr[i]);
            else if(arr[i]<pivot) right.push_back(arr[i]);
            else mid.push_back(arr[i]);
        }
        
        if(left.size()>=k) return quick_select(left, k);
        else if(left.size()+mid.size()<k) return quick_select(right, k-left.size()-mid.size());
        else return pivot;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, k);
    }
};