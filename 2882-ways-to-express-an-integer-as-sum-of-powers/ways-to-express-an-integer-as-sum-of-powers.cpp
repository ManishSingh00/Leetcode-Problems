#define mod 1000000007
class Solution {
public: 
    int dp[305][301];
    int f(int n,int x,int maxi){
        if(n==0) return 1;  
        if(n<0 || maxi == 0) return 0;
        if(dp[n][maxi]!=-1) return dp[n][maxi];

        int ans = 0;
        long long  pwr = pow(maxi,x);
        
        if(pwr<=n) ans = (ans + f(n-pwr,x,maxi-1))%mod;
        ans = (ans + f(n,x,maxi-1))%mod;

        return dp[n][maxi] = ans;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof dp);

        return f(n,x,n);
    }
};