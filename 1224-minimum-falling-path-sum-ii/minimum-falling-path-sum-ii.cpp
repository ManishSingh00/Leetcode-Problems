class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0;j<n;j++){
            dp[0][j] = grid[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini = INT_MAX;
                for(int k=0;k<n;k++){
                    if(k==j) continue;
                    mini = min(mini,grid[i][j] + dp[i-1][k]);
                }
                dp[i][j]= mini;
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans,dp[n-1][j]);
        }
        return ans;
    }
};
