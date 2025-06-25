class Solution {
public:
    int dx[4] = {1,-1,0,0,};
    int dy[4] = {0,0,1,-1};
    int dp[205][205];
    int f(int i,int j,vector<vector<int>>& mat,int m,int n){
        if(i<0 || j< 0 || i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k],nj=j+dy[k];
            
            if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj] > mat[i][j]) ans = max(ans,1+f(i+dx[k],j+dy[k],mat,m,n));
        }

        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n= matrix[0].size();
        memset(dp,-1,sizeof dp);
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,f(i,j,matrix,m,n));
            }
        }

        return ans;
    }
};