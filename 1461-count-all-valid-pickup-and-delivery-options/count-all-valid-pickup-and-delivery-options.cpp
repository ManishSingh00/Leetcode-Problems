    #define ll long long int
    #define mod 1000000007
class Solution {
public:
    ll dp[505];
    ll ncr(int n,int r){
        if(r>n) return 0;
        r = min(r,n-r);
        ll ans = 1;
        for(int i=0;i<r;i++){
            ans *= (n-i);
            ans /= (i+1);
        }

        return ans;
    }
    ll f(int n){
        if(n == 1) return 1;
        if(dp[n]!=-1) return dp[n];

        ll ans = 0;
        ll val = (n*2 - 1) + ncr((n*2 - 1),2);
        val %= mod;
        ans += (f(n-1)*val)%mod;
        ans %= mod;

        return dp[n] = ans;
    }
    int countOrders(int n) {
        memset(dp,-1,sizeof dp);
        return (int)f(n);;

    }
};