class Solution {
public:
    bool greater(string &a, string &b) {
        if(a.size() != b.size())
            return a.size() > b.size();

        return a > b;
    }

    string quick_select(vector<string> arr, int k) {
        vector<string> left;
        vector<string> right;
        vector<string> mid;

        string pivot = arr[rand() % arr.size()];

        for(int i = 0; i < arr.size(); i++) {
            if(greater(arr[i], pivot))
                left.push_back(arr[i]);
            else if(greater(pivot, arr[i]))
                right.push_back(arr[i]);
            else
                mid.push_back(arr[i]);
        }

        if(left.size() >= k)
            return quick_select(left, k);

        else if(left.size() + mid.size() < k)
            return quick_select(
                right,
                k - left.size() - mid.size()
            );

        else
            return pivot;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        return quick_select(nums, k);
    }
};