#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;

using ordered_set = tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ordered_set os;
        ll ans = 0;
        for(int i=n-1;i>=0;i--){

            ll cnt = os.order_of_key({(nums[i]),i});
            os.insert({1LL*nums[i]*2,i});
            ans += cnt;

        }

        return (int)ans;
    }
};