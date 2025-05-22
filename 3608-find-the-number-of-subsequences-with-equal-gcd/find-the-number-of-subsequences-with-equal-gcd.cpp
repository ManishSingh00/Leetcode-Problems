#define ll long long int
#define mod 1000000007
class Solution {
public:
    int n;
    int dp[205][205][205];
    int f(int i,int gcd1,int gcd2,vector<int>& nums){
        if(i==n){
            if(gcd1!=0 && gcd2!=0 && gcd1==gcd2) return 1;
            else return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1) return dp[i][gcd1][gcd2];
        int ans = f(i+1,gcd1,gcd2,nums)%mod;
        ans = (ans + f(i+1,gcd(gcd1,nums[i]),gcd2,nums))%mod;
        ans = (ans + f(i+1,gcd1,gcd(gcd2,nums[i]),nums))%mod;

        return dp[i][gcd1][gcd2]= ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof dp);
        return f(0,0,0,nums); 
    }
};