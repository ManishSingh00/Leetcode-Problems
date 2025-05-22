#define mod 1000000007
class Solution {
public:
    int dp[26][100005];
    long long f(char ch,int t){
        if(t==0) return 1;
        if(dp[ch-'a'][t]!=-1) return dp[ch-'a'][t];

        long long ans = 0;
        if(ch!='z') ans = (ans + f(ch+1,t-1))%mod;
        else{
            ans = (ans + f('a',t-1) + f('b',t-1))%mod;
        }

        return dp[ch-'a'][t]=ans;
    }
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        long long ans = 0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            ans = (ans + f(s[i],t))%mod;
        }
        return (int)ans;
    }
};