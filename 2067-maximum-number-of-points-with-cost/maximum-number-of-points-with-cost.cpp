#define ll long long int
class Solution {
public:
// ll dp[10005][1005];
//     ll f(int i,int j,vector<vector<int>>& mat,int m,int n){
//         if(i==m){
//             return 0;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         ll ans=0;
//         for(int k=0;k<n;k++){
//             ans = max(ans,mat[i][k]-abs(j-k)+f(i+1,k,mat,m,n));
//         }
//         return dp[i][j]=ans;
//     }
    long long maxPoints(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        // memset(dp,-1,sizeof dp);
        // ll ans=0;
        // for(int j=0;j<n;j++){
        //     ans=max(ans,mat[0][j]+f(1,j,mat,m,n));
        // }

        vector<vector<ll>>dp(m,vector<ll>(n));
        for(int i=0;i<n;i++){
            dp[0][i]=mat[0][i];
        }
        ll ans=0;
        for(int i=1;i<m;i++){
            vector<ll>left(n);
            vector<ll>right(n);
            left[0]=dp[i-1][0];
            for(int j=1;j<n;j++){
                left[j]=max(left[j-1]-1,dp[i-1][j]);
            }
            
            right[n-1]=dp[i-1][n-1];
            for(int j=n-2;j>=0;j--){
                right[j]=max(right[j+1]-1,dp[i-1][j]);
            }

            for(int j=0;j<n;j++){
                dp[i][j]=mat[i][j]+max(left[j],right[j]);
            }
        }
        for(int j=0;j<n;j++){
            ans = max(ans,dp[m-1][j]);
        }
        return ans;
        
    }
};