#define ll long long int
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>arr(k,LLONG_MAX);
        ll sum = 0;
        ll ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int z = (i+1)%k;
            if(z==0) ans = max(ans,sum);

            if(arr[z]!=LLONG_MAX){
                ans = max(ans,sum-arr[z]);
            }

            arr[z] = min(arr[z],sum);
        }
        return ans;
    }
};