class Solution {
public:
    int dp[205][205][205];
    int f(int i,int j,int k,string& s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(k<0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=0;
        if(s[i]==s[j]) ans = 2+f(i+1,j-1,k,s);
        ans = max(ans,f(i+1,j,k,s));
        ans = max(ans,f(i,j-1,k,s));
        int allowed_dist=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(allowed_dist<=k){
            ans=max(ans,2 + f(i+1,j-1,k-allowed_dist,s));
        }
        return dp[i][j][k]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return f(0,n-1,k,s);
    }
};