#define ll long long int
class Solution {
public:
    ll dp[15][2][2];
    string suffix;
    ll f(int idx,bool tight, bool leading_zero,int sz,int limit,string str){
        if(idx >= sz){
            // if prefix already < bound's prefix, suffix always ok
            if(tight == false) return 1;
            // prefix == bound's prefix, compare suffix with bound's suffix
            else if(tight==true){
                string bound_suffix = str.substr(sz);
                return suffix <= bound_suffix;
            }

            // bound is basically main string str (here)
        }
        if(dp[idx][tight][leading_zero]!=-1) return dp[idx][tight][leading_zero];
        ll ans = 0;

        int ub = (tight==0)?9:str[idx]-'0';

        for(int dig = 0; dig<=limit && dig<=ub; dig++){
            bool new_tight = tight && (dig == ub);

            if(leading_zero == true && dig == 0){
                ans += f(idx+1,new_tight,true,sz,limit,str);
            }
            else{
                ans += f(idx+1,new_tight,false,sz,limit,str);
            }
        }
        return dp[idx][tight][leading_zero] = ans;
    }
    long long numberOfPowerfulInt(long long l, long long r, int limit, string s) {
        string left = to_string(l-1);
        string right = to_string(r);
        suffix = s;
        memset(dp,-1,sizeof dp);
        ll x = 0,y=0;
        if((int)right.length()-(int)s.length() >= 0) x = f(0,true,true,(int)right.length()-(int)s.length(),limit,right);

        memset(dp,-1,sizeof dp);
        if((int)left.length()-(int)s.length() >= 0) y = f(0,true,true,(int)left.length()-(int)s.length(),limit,left);
        cout<<x<<" "<<y;
        return x-y;
    }
};