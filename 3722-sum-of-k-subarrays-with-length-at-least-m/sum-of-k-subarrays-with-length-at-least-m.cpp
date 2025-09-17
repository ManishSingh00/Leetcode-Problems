#define ll long long int
class Solution {
public:
    ll dp[2001][2001][2];
    ll f(int i,int k,bool started,int m,vector<ll>& pre,vector<int>& nums,int n){
        if(i == n) {
            if(k > 0) return LLONG_MIN/2;
            return 0;
        }

        if(dp[i][k][started] !=-1) return dp[i][k][started];
        ll ans = LLONG_MIN;
        if(started == false){
            ans = max(ans,f(i+1,k,started,m,pre,nums,n));

            if(i+m-1 < n && k>0){
                ll sum = pre[i+m-1] - (i==0?0:pre[i-1]);
                ans = max(ans,sum + f(i+m,k-1,true,m,pre,nums,n));
            }
        }
        if(started == true){
            ans = max(ans, nums[i] + f(i+1,k,started,m,pre,nums,n));
            // explore new way
            ans = max(ans, f(i,k,false,m,pre,nums,n));
        }
        
        return dp[i][k][started] = ans;
    }
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<ll>pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        // memset(dp,-1,sizeof dp);
        for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
        for(int b = 0; b < 2; b++)
            dp[i][j][b] = -1;

        return f(0,k,false,m,pre,nums,n);
    }
};