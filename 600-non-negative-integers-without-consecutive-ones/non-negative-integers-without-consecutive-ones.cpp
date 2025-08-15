class Solution {
public:
    int dp[35][2][2];
    int f(int idx,bool tight,int prev,string& s){
        if(idx >= s.length()) return 1;
        if(dp[idx][tight][prev] != -1) return dp[idx][tight][prev];
        int ans = 0;

        int ub = (tight == 0)?1:s[idx] - '0';

        for(int dig=0;dig<=ub;dig++){
            bool new_tight = tight && (dig == ub);
            if(prev == 1 && dig == 1) continue;
            else ans += f(idx+1,new_tight,dig,s);
        }

        return dp[idx][tight][prev] =  ans;

    }
    int findIntegers(int n) {
        string s="";
        while( n ){
            char rem=(n % 2)+'0';
            s+=rem;
            n/=2;
        }
        reverse(s.begin(), s.end());
        memset(dp,-1,sizeof dp);
        return f(0,true,0,s);
    }
};