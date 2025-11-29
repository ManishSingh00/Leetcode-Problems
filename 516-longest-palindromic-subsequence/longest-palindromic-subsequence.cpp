class Solution {
public:
    int n;
    int dp[1005][1005];
    int f(string &s ,int i,int j){
        if(i==n || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i]==s[j]) ans = 1+f(s,i+1,j-1);
        else {
            ans = max(ans,max(f(s,i+1,j),f(s,i,j-1)));
        }

        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        n=s.size();
        memset(dp,-1,sizeof dp);
        return f(s,0,n-1);
    }
};