#define ll long long int
class Solution {
public:
    ll dp[105][25][105];
    ll f(int i,int clrcode, int grp_sz,int m,int n,vector<int>& houses, vector<vector<int>>& cost,int tar){
        if(i==m){
            if(grp_sz == tar){
                return 0;
            }
            else return 1e8;
        }    
        // cout<<clrcode<<endl;
        if(dp[i][clrcode+1][grp_sz]!=-1) return dp[i][clrcode+1][grp_sz];
        ll ans = 1e8;

        for(int j=0;j<n;j++){
            if(houses[i]==0){
                if(clrcode == -1){
                    ans = min(ans,cost[i][j] + f(i+1,j+1,grp_sz+1,m,n,houses,cost,tar));
                }
                else{
                    ans = min(ans,cost[i][clrcode-1] + f(i+1,clrcode,grp_sz,m,n,houses,cost,tar));
                    if(clrcode-1 != j) ans = min(ans,cost[i][j] + f(i+1,j+1,grp_sz+1,m,n,houses,cost,tar));
                }
            }

            else{ // houses[i]!=0
                if(clrcode == houses[i]) ans = min(ans,f(i+1,clrcode,grp_sz,m,n,houses,cost,tar));
                else ans = min(ans,f(i+1,houses[i],grp_sz+1,m,n,houses,cost,tar));
            }
        }

        return dp[i][clrcode+1][grp_sz] = ans;

    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        ll ans = f(0,-1,0,m,n,houses,cost,target);
        if(ans == 1e8) return -1;
        else return ans;
    }
};