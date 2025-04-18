#define ll long long int
#define mod 1000000007
class Solution {
public:
ll dp[25][2][2][405];
    ll f(int pos,bool tight,bool leading_zero,int sum,int mins,int maxs,string& nums){
        if(pos==nums.length()){
            if(leading_zero==false && sum >= mins && sum <= maxs) return 1;
            else return 0;
        }
        if(dp[pos][tight][leading_zero][sum]!=-1) return dp[pos][tight][leading_zero][sum];
        ll ans=0;
        int ub=(tight==0)?9:nums[pos]-'0';
        for(int dig=0;dig<=ub;dig++){
            bool new_tight = tight && (dig == ub);
            if(leading_zero == true){
                if(dig == 0) ans += f(pos+1,new_tight,true,sum,mins,maxs,nums);
                else if(sum+dig<=maxs) ans += f(pos+1,new_tight,false,sum+dig,mins,maxs,nums); //You should never check sum >= mins inside the loop,because valid numbers can have sum below min_sum midway through the number, but still reach a valid range by the end.
            }
            else{
                if(sum+dig<=maxs) ans += f(pos+1,new_tight,false,sum+dig,mins,maxs,nums);
            }
        }
        return dp[pos][tight][leading_zero][sum] = ans%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof dp);
        ll x = f(0,true,true,0,min_sum,max_sum,num2);

        memset(dp,-1,sizeof dp);
        ll y = f(0,true,true,0,min_sum,max_sum,num1);

        bool flag=true;
        int sum=0;
        for(int i=0;i<num1.length();i++){
            sum += num1[i]-'0';
        }
        // cout<<sum;
        if(sum > max_sum || sum < min_sum) flag = false;

        return (x - y + (flag==true?1:0) + mod) % mod;

    }
};