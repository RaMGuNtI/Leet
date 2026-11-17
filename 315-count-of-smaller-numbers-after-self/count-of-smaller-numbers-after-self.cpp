#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        using ordered_set = tree<
            pair<int, int>,
            null_type,
            less<pair<int, int>>,
            rb_tree_tag,
            tree_order_statistics_node_update
        >;

        ordered_set st;

        int n = nums.size();
        vector<int> res(n, 0);

        int unq_id = 1;

        for (int i = n - 1; i >= 0; i--) {

            st.insert({nums[i], unq_id++});

            res[i] = st.order_of_key({nums[i], 0});
        }

        return res;
    }
};