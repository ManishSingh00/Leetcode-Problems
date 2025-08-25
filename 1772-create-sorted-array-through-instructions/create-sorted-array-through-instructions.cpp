#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define mod 1000000007
using namespace __gnu_pbds;

using ordered_set = tree<pair<ll,int>, null_type, less<pair<ll,int>>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    int createSortedArray(vector<int>& arr) {
        int n = arr.size();
        ll final_ans = 0;

        ordered_set os;

        for(int i=0;i<n;i++){
            int val = arr[i];

            int lo = os.order_of_key({val,0});
            
            int hi = os.size() - os.order_of_key({val,INT_MAX});

            int cnt = min(lo,hi);
            final_ans += cnt%mod;
            os.insert({val,i});
        }

        return final_ans%mod;
    }
};