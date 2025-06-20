class Solution {
public:
    int dp[21][10001];
    int f(int i,int diff,vector<int>& nums,int n){
        if(i==n){
            if(diff==0) return 0;
            else return INT_MIN;
        }
        if(dp[i][diff+5000]!=-1) return dp[i][diff+5000];
        int ans = f(i+1,diff,nums,n);
        ans = max(ans,nums[i]+f(i+1,diff+nums[i],nums,n));
        ans = max(ans,nums[i]+f(i+1,diff-nums[i],nums,n));

        return dp[i][diff+5000]=ans;
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = 0;
        memset(dp,-1,sizeof dp);
        return f(0,0,rods,n)/2;
    }
};