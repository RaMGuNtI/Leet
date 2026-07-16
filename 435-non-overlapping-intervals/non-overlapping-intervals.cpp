class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int j = 0;

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[j][1] <= intervals[i][0]) {
                j = i;
            }
            else {
                ans++;

                if (intervals[i][1] < intervals[j][1])
                    j = i;
            }
        }

        return ans;
    }
};