#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll dp[105][2][2][11];
    ll f(int pos,bool tight,bool leadingzero,int prev,string& s){
        if (pos == s.length()) return leadingzero ? 0 : 1;
        if(dp[pos][tight][leadingzero][prev]!=-1) return dp[pos][tight][leadingzero][prev];
        ll ans=0;
        int ub=(tight==0)?9:s[pos]-'0';
        for(int dig=0;dig<=ub;dig++){
            bool new_tight=tight&&(dig==ub);
            if(leadingzero == true){
                if(dig==0) ans += f(pos+1,new_tight,true,10,s);
                else ans += f(pos+1,new_tight,false,dig,s);
            }
            else{
                if(prev!=10 && abs(prev-dig)==1) ans += f(pos+1,new_tight,false,dig,s);
            }
        }
        return dp[pos][tight][leadingzero][prev]=ans%mod;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof dp);
        ll x=f(0,true,true,10,high);

        memset(dp,-1,sizeof dp);
        ll y=f(0,true,true,10,low);

        bool flag=true;
        for(int i=1;i<low.length();i++){
            if(abs(low[i]-low[i-1])!=1){
                flag=false;
            }
        }
        return (x-y+(flag==true?1:0)+mod)%mod;
    }
};