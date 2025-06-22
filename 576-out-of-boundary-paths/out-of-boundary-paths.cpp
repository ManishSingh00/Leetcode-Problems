#define mod 1000000007
class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    int dp[51][51][51];
    int f(int i,int j,int m,int n,int move,int maxi){
        if(i<0 || j<0 || i>=m || j>=n) return 1;
        if(move == maxi) return 0;
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        int ans = 0;
        for(int k= 0;k<4;k++){
            ans = (ans + f(i+dx[k],j+dy[k],m,n,move+1,maxi))%mod;
        }
        return dp[i][j][move] = ans;
    }
    int findPaths(int m, int n, int maxi, int sr, int sc) {
        memset(dp,-1,sizeof dp);
        return f(sr,sc,m,n,0,maxi);
    }
};