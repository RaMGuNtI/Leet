#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        using ordered_set = tree<
            pair<long long, int>,
            null_type,
            less<pair<long long, int>>,
            rb_tree_tag,
            tree_order_statistics_node_update
        >;

        ordered_set st;

        int n = nums.size();
        int res = 0;

        for (int i = n - 1; i >= 0; i--) {
            res += st.order_of_key({nums[i], -1});

            st.insert({2LL * nums[i], i});
        }

        return res;
    }
};