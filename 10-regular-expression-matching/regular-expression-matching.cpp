class Solution {
public:
    int dp[25][25];
    bool f(string &s , string& p,int i,int j,int n,int m){
        if(i == n && j == m) return true;
        if(i<n && j>=m) return false;
        if(i>=n && j<m){
            // Remaining pattern must be like "a*b*c*", i.e., even length and
            // every second char is '*'
            if((m-j)%2!=0) return false; // if rem len is odd
            for(int k=j+1;k<m;k+=2){ // checking for alternate '*'
                if(p[k]!='*') return false; 
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;

        if(s[i] == p[j] || p[j]=='.'){
            ans = f(s,p,i+1,j+1,n,m);
        }
        // i have 2 options ( either skip the *  or consume it if current matches)
        if(j+1< m && p[j+1] == '*'){
            ans = ans || f(s,p,i,j+2,n,m);

            if(s[i] == p[j] || p[j]=='.'){
                ans = ans || f(s,p,i+1,j,n,m);
            }
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