class Solution {
public:
    int dp[1005][1005];
    int f(int i,int prevIdx,vector<int>& nums, int n){
        if(i>=n-1){
            return max(nums[prevIdx], i==n-1?nums[i]:0);
        }
        if(dp[i][prevIdx]!=-1) return dp[i][prevIdx];

        int cost = max(nums[i] , nums[i+1]) + f(i+2,prevIdx,nums,n);
        cost = min(cost, max(nums[prevIdx],nums[i+1]) + f(i+2,i,nums,n));
        cost = min(cost,max(nums[prevIdx],nums[i]) + f(i+2,i+1,nums,n));

        return dp[i][prevIdx] = cost;
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);

        return f(1,0,nums,n);
    }
};