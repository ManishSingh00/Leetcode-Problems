class Solution {
public:
    int dp[55][55];
    int f(int i,int j,vector<int>& values){
        if(j - i < 2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1;k<j;k++){
            ans = min(ans, values[i]*values[j]*values[k] + f(i,k,values) + f(k,j,values));
        }

        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof dp);
        return f(0,values.size()-1,values);
    }
};