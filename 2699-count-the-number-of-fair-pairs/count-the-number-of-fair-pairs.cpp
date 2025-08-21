#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;

using ordered_set = tree<pair<ll,int>, null_type, less<pair<ll,int>>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        ordered_set os;
        int id = 0;

        ll ans = 0;
        for(int i=0;i<n;i++){
            int left = lower - nums[i];
            int right = upper - nums[i];

            ll cnt = os.order_of_key({right,INT_MAX}) - os.order_of_key({left,INT_MIN});
            ans += cnt;

            os.insert({nums[i],id++});
        }

        return ans;
    }
};