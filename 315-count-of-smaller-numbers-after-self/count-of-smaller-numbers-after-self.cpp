#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ordered_set os;
        for (int i = n - 1; i >= 0; i--) {
            int cnt = os.order_of_key({nums[i],i});
            ans[i] = cnt;
            os.insert({nums[i],i});
        }
        return ans;
    }
};
