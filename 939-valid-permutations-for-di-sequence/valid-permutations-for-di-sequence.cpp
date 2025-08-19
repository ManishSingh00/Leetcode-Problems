#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll dp[205][205];
    bool vis[205];
    ll f(int i,int prev,string& s,int n){
        if(i>=n){
            return 1;
        }
        if(dp[i][prev]!=-1) return dp[i][prev];

        ll ans = 0;
        if(s[i] == 'D'){
            for(int x = 0;x<prev;x++){
                if(vis[x]== false){
                    vis[x] = true;
                    ans = (ans + f(i+1,x,s,n))%mod;
                    vis[x] = false;
                }
            }
        }
        else if(s[i]=='I'){
            for(int x = prev+1;x<=n;x++){
                if(vis[x]== false){
                    vis[x] = true;
                    ans = (ans + f(i+1,x,s,n))%mod;
                    vis[x] = false;
                }
            }
        }

        return dp[i][prev] = ans %mod;
    }
    int numPermsDISequence(string s) {
        int n = s.length();
        memset(dp,-1,sizeof dp);
        memset(vis,false,sizeof vis);

        ll ans = 0;
        for(int i=0;i<=n;i++){
            vis[i] = true;
            ans = (ans + f(0,i,s,n))%mod;
            vis[i] = false;
        }

        return ans;
    }
};