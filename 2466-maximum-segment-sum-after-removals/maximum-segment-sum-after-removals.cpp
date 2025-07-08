#define ll long long int
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) {
        int n = nums.size();
        vector<ll>pre(n,0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        multiset<ll>mt; // store sums
        mt.insert(pre[n-1]);
        set<int>remove; // store removed index
        remove.insert(-1);
        remove.insert(n);

        vector<ll>ans(n,0);
        for(int i=0;i<n;i++){
            int idx = q[i];

            auto itr = remove.lower_bound(idx);
            int r = *itr;
            int l = *(prev(itr));

            ll curr_sum = pre[r-1] - (l==-1?0:pre[l]);
            mt.erase(mt.find(curr_sum));

            
            ll left = ( idx == 0 ? 0 : pre[idx-1] ) - (l == -1? 0 : pre[l] );
            ll right = (r == 0 ? 0 : pre[r-1]) - pre[idx];
            mt.insert(left);
            mt.insert(right);

            remove.insert(idx);
            ans[i] = *(mt.rbegin());


        }

        return ans;

    }
};