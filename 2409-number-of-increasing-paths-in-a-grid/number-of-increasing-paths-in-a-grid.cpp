#define ll long long int
#define mod 1000000007
class Solution {
public:
    int dx[4] = {1,-1,0,0,};
    int dy[4] = {0,0,1,-1};
    ll dp[1005][1005];
    ll f(int i,int j,vector<vector<int>>& mat,int m,int n){
        if(i<0 || j< 0 || i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        ll ans = 1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k],nj=j+dy[k];
            
            if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj] > mat[i][j]) ans = (ans + f(i+dx[k],j+dy[k],mat,m,n))%mod;
        }

        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& matrix) {
        int m = matrix.size(), n= matrix[0].size();
        memset(dp,-1,sizeof dp);
        ll ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = (ans + f(i,j,matrix,m,n))%mod;
            }
        }

        return (int)ans;
    }
};