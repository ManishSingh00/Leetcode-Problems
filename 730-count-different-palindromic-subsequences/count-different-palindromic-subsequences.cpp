#define mod 1000000007
class Solution {
public:
    int dp[1005][1005];
    int f(int i,int j,string& s){
        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            int l = i+1;
            int r = j-1;
            while(l<=r && s[l]!=s[i]) l++;
            while(l<=r && s[r]!=s[j]) r--;
            if(l>r){
                dp[i][j] = (2*f(i+1,j-1,s) + 2)%mod;
            }
            else if(l==r){  
                dp[i][j] = (2*f(i+1,j-1,s) + 1)%mod;
            }
            else{
                dp[i][j] = ((2*f(i+1,j-1,s))%mod - f(l+1,r-1,s)%mod + mod) %mod;
            }
        }
        else dp[i][j] = ((f(i+1,j,s)%mod + f(i,j-1,s)%mod)%mod - f(i+1,j-1,s)%mod + mod )%mod;


        return dp[i][j];
    }
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        memset(dp,-1,sizeof dp);
        return f(0,n-1,s);
    }
};