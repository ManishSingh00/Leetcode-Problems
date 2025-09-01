#define ll long long int
#define mod 1000000007
class Solution {
public:
    int dp[55][55][105];
    int f(int i, int cnt,int prev,int n,int m){
        if(i == n) {
            if(cnt == 0) return 1;
            else return 0;
        }
        if(dp[i][cnt][prev+1] !=-1) return dp[i][cnt][prev+1];
        ll ans = 0;

        for(int j = 1;j<=m;j++){
            if(j > prev){
                if(cnt > 0) ans += f(i+1,cnt-1,j,n,m)%mod;
            }
            else  ans += f(i+1,cnt,prev,n,m)%mod;

            ans %= mod;
        }

        return dp[i][cnt][prev+1] = ans%mod;

    }
    int numOfArrays(int n, int m, int k) {
        if(m<k) return 0;
        memset(dp,-1,sizeof dp);
        return f(0,k,-1,n,m);
    }
};