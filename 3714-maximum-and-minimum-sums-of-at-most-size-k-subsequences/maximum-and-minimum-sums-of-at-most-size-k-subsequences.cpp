#define ll long long int
#define mod 1000000007
class Solution {
public:
    int dp[100005][72];
    int f(int i,int len,int n,vector<int>& nums){
        if(len == 1 || i == n-1) return 1;
        if(dp[i][len]!=-1) return dp[i][len];

        ll ans = 0;
        ans += f(i+1,len,n,nums);
        ans %= mod;
        ans += f(i+1,len-1,n,nums);
        ans %= mod;

        return dp[i][len] = ans;
    }
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof dp);

        ll ans = 0;
        for(int i=0;i<n;i++){
            int cnt_min = f(i,k,n,nums);
            int cnt_max = f(n-i-1,k,n,nums);

            ans += 1LL*nums[i]*cnt_min;
            ans %= mod;
            ans += 1LL*nums[i]*cnt_max;
            ans %= mod;
        }

        return ans;
    }
};