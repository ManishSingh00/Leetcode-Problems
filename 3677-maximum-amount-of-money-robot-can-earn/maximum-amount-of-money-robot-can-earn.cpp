class Solution {
public:
#define  ll long long int
    ll dp[505][505][3];
    bool done[505][505][3];
    ll f(int i,int j,int k,vector<vector<int>>& coins,int m,int n){
        if(i>=m || j>=n) return -1e18;
        // if (i == m - 1 && j == n - 1) {
        //     if (coins[i][j]>= 0) {
        //         return coins[i][j];
        //     }
        //     if(k) return 0;
        //     else return coins[i][j];
            
        // }
        if (i == m - 1 && j == n - 1) { 
            if (coins[i][j] < 0 && k > 0) return 0;
            return coins[i][j];
        }
        if(done[i][j][k]) return dp[i][j][k];

        // if(coins[i][j]>=0){
            // ans = max(ans,coins[i][j]+f(i+1,j,k,coins,m,n));
        ll ans = -1e18;
        ans=coins[i][j] + max(f(i+1,j,k,coins,m,n),f(i,j+1,k,coins,m,n));
            // ans = max(ans,coins[i][j]+f(i,j+1,k,coins,m,n));
        // }
        // if(coins[i][j]<0){
            if(k>0){
                ans = max({ans,f(i+1,j,k-1,coins,m,n),f(i,j+1,k-1,coins,m,n)});
                // ans = max(ans,f(i,j+1,k-1,coins,m,n));
            }
            // ans = max(ans, coins[i][j] + f(i + 1, j, k, coins, m, n)); 
            // ans = max(ans, coins[i][j] + f(i, j + 1, k, coins, m, n));
            done[i][j][k]=true;
        return dp[i][j][k] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        memset(dp,-1,sizeof dp);
        memset(done,false,sizeof done);
        return (int)f(0,0,2,coins,m,n);

    }
};