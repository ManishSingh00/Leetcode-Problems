#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll dp[1005][1005];
    ll f(int n,int k){
        if(n==0 && k==0) return 1;
        if(n==0) return 0;
        if(k==0) return 1;
        if(dp[n][k]!=-1) return dp[n][k];

        ll ans = 0;
        // for(int i=0;i<=min(k,n-1);i++){  // this method will lead TC of n*k*min(n,k), which shold give TLE , but Leetcode did not have good test case and it get submitted 
        //     ans += f(n-1,k-i);
        // }

        // OPTIMIZED LOGIC, Using sliding window which will come to mind after writing bottom up approach and makinf DP tables and recognizing the pattern

        ans = (ans + f(n-1,k) + f(n,k-1))%mod;
        if(k-n>=0) ans = (ans - f(n-1,k-n) + mod)%mod;

        return dp[n][k] = ans%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof dp);
        return (int)f(n,k);
    }
};
