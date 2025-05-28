class Solution {
public:
    int dp[14][1<<13];
    int f(int i,int mask,int n,int m,vector<vector<int>>& cost){
        if(i==n) {
            if(mask == (1<<m)-1) return 0;
            else return 1e5;
        }
        if(dp[i][mask]!=-1) return dp[i][mask];

        int ans = 1e5;
        for(int j=0;j<m;j++){
           ans = min(ans,cost[i][j]+f(i+1,mask|(1<<j),n,m,cost));
           if(!(mask & (1<<j))){
                ans = min(ans,cost[i][j]+f(i,mask|(1<<j),n,m,cost));
           }
        }

        return dp[i][mask]= ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();

        memset(dp,-1,sizeof dp);
        return f(0,0,n,m,cost);

    }
};