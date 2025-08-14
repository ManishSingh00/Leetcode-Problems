class Solution {
public:
    int dp[2002][2002];
    bool f(string &s, string& p,int i,int j,int n,int m){
        if(i == n && j == m) return true;
        if(i<n && j>=m) return false;
        if(i>=n && j<m){
            while(j<m){
                if(p[j]!='*') return false;
                j++;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        bool ans = false;
        if(s[i] == p[j] || p[j] == '?') ans = f(s,p,i+1,j+1,n,m);
        else if(p[j] =='*') {
            ans = ans || f(s,p,i+1,j,n,m);
            ans = ans || f(s,p,i,j+1,n,m);
        }

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        memset(dp,-1,sizeof dp);
        return f(s,p,0,0,n,m);
    }
};