class Solution {
public:
// vector<list<pair<int,int>>>gr;
    int dp[55][55];
    int dfs(int row,int col,vector<vector<int>>& grid, vector<vector<int>>& cost,int m ,int n){
        if(row==m-1) return grid[row][col];
        if(row>=m) return INT_MIN;
        if(dp[row][col]!=-1) return dp[row][col];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,grid[row][col]+cost[grid[row][col]][i]+dfs(row+1,i,grid,cost,m,n));
        }
        return dp[row][col]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof dp);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dfs(0,i,grid,cost,m,n));
        }
        return ans;
    }
};