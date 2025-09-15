class Solution {
public:
    int dp[10][1<<10][2][2];
    int f(int idx,int mask,bool tight,bool leading_zero,string &s,int n){
        if(idx >= n) return 1;
        if(dp[idx][mask][tight][leading_zero] != -1) return dp[idx][mask][tight][leading_zero];

        int ans = 0;
        int ub = tight==0?9:s[idx]-'0';
        for(int dig = 0;dig <= ub;dig++){
            bool new_tight = tight && (dig==ub);
            if(leading_zero == true && dig == 0){
                ans += f(idx+1,mask,new_tight,true,s,n);
            }
            else{
                if((mask >> dig) & 1) continue;
                int new_mask = mask | (1<<dig);
                ans += f(idx+1,new_mask,new_tight,false,s,n);
            }
        }

        return dp[idx][mask][tight][leading_zero] = ans;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        int ans = f(0,0,true,true,s,s.length());
        return ans - 1;

    }
};