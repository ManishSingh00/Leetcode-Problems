class Solution {
public:
    int dp[100005];
    bool f(int n){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        bool ans = false;
        for(int i=1;i<=sqrt(n);i++){
           bool opponent=f(n-i*i);
           if(opponent == false) ans = true;
        }

        return dp[n] = ans;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof dp);
        return f(n);
    }
};