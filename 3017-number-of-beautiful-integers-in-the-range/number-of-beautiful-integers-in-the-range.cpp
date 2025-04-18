class Solution {
public:
    int dp[20][2][2][20][20][100];
    int f(int pos,bool tight,bool leading_zero,int odd,int even,int mod,string& num,int k){
        if(pos==num.length()){
            if(leading_zero == false && odd == even && mod ==0) return 1; 
            else return 0;
        }
        if(dp[pos][tight][leading_zero][odd][even][mod]!=-1) return dp[pos][tight][leading_zero][odd][even][mod];
        int ans=0;
        int ub=(tight==0)?9:num[pos]-'0';
        for(int dig = 0; dig <= ub; dig++){
            bool new_tight = tight && (dig==ub);
            int new_mod = (mod * 10 + dig) % k;

            if(leading_zero == true){
                if(dig == 0) ans += f(pos+1,new_tight,true,odd,even,mod,num,k);
                else if(dig % 2 == 0){
                    // s+=(char)('0'+ dig);
                    ans += f(pos+1,new_tight,false,odd,even+1,new_mod,num,k);
                }
                else{
                    // s+=(char)('0'+ dig);
                    ans += f(pos+1,new_tight,false,odd+1,even,new_mod,num,k);
                }
            }
            else{
                if(dig % 2 == 0){
                    // s+=(char)('0'+ dig);
                    ans += f(pos+1,new_tight,false,odd,even+1,new_mod,num,k);
                }
                else{
                    // s+=(char)('0'+ dig);
                    ans += f(pos+1,new_tight,false,odd+1,even,new_mod,num,k);
                }
            }
        }
        return dp[pos][tight][leading_zero][odd][even][mod] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l=to_string(low);
        string r=to_string(high);
        memset(dp,-1,sizeof dp);
        int x = f(0,true,true,0,0,0,r,k);

        memset(dp,-1,sizeof dp);
        int y = f(0,true,true,0,0,0,l,k);

          // checking low
        int odd=0,even=0;
        bool flag=false;
        if(low % k==0){
            for(int i=0;i<l.size();i++){
                if(l[i]%2==0) even++;
                else odd++;
            }
        }
        if(odd!=0 && even==odd) flag=true;

        return x - y + flag;

    }
};