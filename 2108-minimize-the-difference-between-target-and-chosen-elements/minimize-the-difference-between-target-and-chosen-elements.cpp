class Solution {
public:
    int dp[75][4905];
    vector<vector<bool>>vis;
    unordered_set<int>st;
    int f(int i,vector<vector<int>>& mat,int tar,int sum,int m,int n){
        if(i==m){
            return abs(tar-sum);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=1e5;
        for(int k=0;k<n;k++){
            ans = min(ans,f(i+1,mat,tar,sum+mat[i][k],m,n));
        }
        return dp[i][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int tar) {
        int m=mat.size(),n=mat[0].size();
        memset(dp,-1,sizeof dp);
        int ans=1e5;
        for(int j=0;j<n;j++){
            ans = min(ans,f(1,mat,tar,mat[0][j],m,n));
        }
        return ans;
    }
};