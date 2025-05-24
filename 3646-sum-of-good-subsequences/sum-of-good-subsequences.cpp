#define mod 1000000007
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>cnt,sum;

        for(int i=0;i<n;i++){
            int x = nums[i];
            cnt[x] += (cnt[x-1] + cnt[x+1] + 1)%mod;
            cnt[x] %= mod;

            sum[x] += (sum[x-1]%mod + sum[x+1]%mod)%mod;
            sum[x]%=mod;
            sum[x] += (long long)(cnt[x-1] + cnt[x+1] + 1)%mod * x%mod;
            sum[x]%=mod;
        }
        int ans = 0;
        for(auto x:sum){
            ans += (x.second);
            ans %= mod;
        }

        return ans;

    }
};