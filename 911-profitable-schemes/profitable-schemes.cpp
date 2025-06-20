#define mod 1000000007
class Solution {
public:
    int dp[105][105][105];
    int f(int i,int size,int prf,int min_p,int n,int n1,vector<int>& group, vector<int>& profit){
        prf = min(prf,min_p);
        if(i==n1){
            if(size<=n && prf>=min_p) return 1;
            else return 0;
        }
        if(dp[i][size][prf]!=-1) return dp[i][size][prf];

        int ans = f(i+1,size,prf,min_p,n,n1,group,profit);
        if(size+group[i] <= n && prf+profit[i] >=profit[i]){
            ans = (ans + f(i+1,size+group[i],prf+profit[i],min_p,n,n1,group,profit))%mod;
        }

        return dp[i][size][prf] = ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int n1 = group.size();
        memset(dp,-1,sizeof dp);
        return f(0,0,0,minProfit,n,n1,group,profit);
    }
};