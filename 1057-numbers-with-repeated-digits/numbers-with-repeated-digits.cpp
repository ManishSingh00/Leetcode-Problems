class Solution {
public:
    string s;
    int dp[12][2][1<<10][2][2];
    int f(int idx,bool tight,int mask,bool flag,bool leading_zero,int sz){ // counting number of integerws which have all unique digits
        if(idx == sz){
            if(flag == true && leading_zero == false) return 1;
            else return 0;
        }
        if(dp[idx][tight][mask][flag][leading_zero]!= -1) return dp[idx][tight][mask][flag][leading_zero];

        int ans = 0;
        int ub = (tight==0)?9:s[idx]-'0';

        for(int dig = 0;dig<=ub;dig++){
            bool new_tight = tight && (dig == ub);

            if(leading_zero == true && dig == 0){
                ans += f(idx+1,new_tight,mask,false,true,sz);
            }

            else if((mask & (1<<dig)) != 0){
                ans += f(idx+1,new_tight,mask,true,false,sz);
                // continue;
            }
            else ans += f(idx+1,new_tight,mask|(1<<dig),flag,false,sz);
        }

        return dp[idx][tight][mask][flag][leading_zero] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof dp);
        return f(0,true,0,false,true,s.length());
    }
};