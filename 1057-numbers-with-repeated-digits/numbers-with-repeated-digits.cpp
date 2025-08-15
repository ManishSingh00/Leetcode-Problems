class Solution {
public:
    string s;
    int dp[12][2][1<<10][2];
    int f(int idx,bool tight,int mask,bool leading_zero,int sz){ // counting number of integerws which have all unique digits
        if(idx == sz){
            if(leading_zero == false) return 1;
            else return 0;
        }
        if(dp[idx][tight][mask][leading_zero]!= -1) return dp[idx][tight][mask][leading_zero];

        int ans = 0;
        int ub = (tight==0)?9:s[idx]-'0';

        for(int dig = 0;dig<=ub;dig++){
            bool new_tight = tight && (dig == ub);

            if(leading_zero == true && dig == 0){
                ans += f(idx+1,new_tight,mask,true,sz);
            }

            else if((mask & (1<<dig)) != 0){
                continue;
            }
            else ans += f(idx+1,new_tight,mask|(1<<dig),false,sz);
        }

        return dp[idx][tight][mask][leading_zero] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof dp);
        return n - f(0,true,0,true,s.length());
    }
};