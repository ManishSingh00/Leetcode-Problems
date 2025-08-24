#define ll long long int
#define mod 1000000007
class Solution {
public:
    int dp[20005][26];
    int m;
    int f(int i,int prev){
        if(i==m-1) return 1;
        if(dp[i][prev]!=-1) return dp[i][prev];
        ll ans = 0;

        if(prev == 'a'-'a'){
            ans += (f(i+1,'e'-'a'))%mod;
        }
        else if(prev == 'e'-'a'){
            ans += (f(i+1,'a'-'a'))%mod;
            ans += (f(i+1,'i'-'a'))%mod;

        }
        else if(prev == 'i'-'a'){
            ans += (f(i+1,'a'-'a'))%mod;
            ans += (f(i+1,'e'-'a'))%mod;
            ans += (f(i+1,'o'-'a'))%mod;
            ans += (f(i+1,'u'-'a'))%mod;
        }
        else if(prev == 'o'-'a'){
            ans += (f(i+1,'i'-'a'))%mod;
            ans += (f(i+1,'u'-'a'))%mod;
        }
        else if(prev == 'u'-'a'){
            ans += (f(i+1,'a'-'a'))%mod;
        }

        return dp[i][prev] = ans%mod;
    }
    int countVowelPermutation(int n) {
        m= n ;
        memset(dp,-1,sizeof dp);
        int ans = f(0,'a'-'a')%mod;
        ans = (ans + f(0,'e'-'a')%mod)%mod;
        ans = (ans + f(0,'i'-'a')%mod)%mod;
        ans = (ans + f(0,'o'-'a')%mod)%mod;
        ans = (ans + f(0,'u'-'a')%mod)%mod;

        // return (f(0,'a'-'a')%mod+f(0,'e'-'a')%mod+f(0,'i'-'a')%mod+f(0,'o'-'a')%mod+f(0,'u'-'a')%mod)%mod;
        return ans;
    }
};