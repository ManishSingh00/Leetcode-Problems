#define mod 1000000007
class Solution {
public:
    vector<vector<int>>moves;
    int dp[5005][10];
    int f(int n,int val){
        if(n==1) return 1;
        if(dp[n][val]!=-1) return dp[n][val];

        int ans = 0;
        for(auto x:moves[val]){
            ans = (ans + f(n-1,x))%mod;
        }

        return dp[n][val] = ans%mod;
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof dp);
        moves = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        int ans = 0;
        for(int i=0;i<10;i++){
            ans = (ans + f(n,i))%mod;
        }

        return ans%mod;

    }
};