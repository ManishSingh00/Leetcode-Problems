#define mod 1000000007
#define ll long long int
class Solution {
public:
    int dp[105][105];
    int f(int i,int j,int k,int goal,int n){
        if(i == goal){
            if(j == n) return 1;
            else return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        ll ans = 0;
        // add a new song
        ans += 1LL*f(i+1,j+1,k,goal,n)*(n-j);
        ans %= mod;

        if(j>k){ // add a repeated song (not in last k)
            ans += 1LL*f(i+1,j,k,goal,n)*(j-k);
            ans %= mod;
        } 

        return dp[i][j] = ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof dp);
        return f(0,0,k,goal,n);
    }
};