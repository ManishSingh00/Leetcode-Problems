class Solution {
public:
    int dp[40005][5];
    int f(int i,int rem,int n,vector<int>& nums){
        if(i==n){
            if(rem == 0) return 0;
            else return INT_MIN;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int ans = 0;
        ans = f(i+1,rem,n,nums);
        ans = max(ans,nums[i] + f(i+1,(rem+nums[i])%3,n, nums));

        return dp[i][rem] = ans;
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return f(0,0,n,nums);
    }
};