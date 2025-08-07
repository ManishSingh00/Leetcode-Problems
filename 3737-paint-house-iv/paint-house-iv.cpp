#define ll long long int
class Solution {
public:
    ll dp[100005][4][4];
    ll f(int idx,int prev, int nxt, vector<vector<int>>& cost,int n){
        if(idx>=n/2) return 0;

        if(dp[idx][prev+1][nxt+1]!=-1) return dp[idx][prev+1][nxt+1];

        ll ans = LLONG_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j && i!=prev && j!=nxt){
                    ans = min(ans,cost[idx][i] + cost[n-idx-1][j] + f(idx+1,i,j,cost,n));
                }
            }
        }

        return dp[idx][prev+1][nxt+1] = ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp,-1,sizeof dp);
        return f(0,-1,-1,cost,n);
    }
};