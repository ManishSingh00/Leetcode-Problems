class Solution {
public:
    int dp[1<<14];
    int f(int mask,vector<int>& nums,int n){
        if(mask == (1<<n)-1) return 0;
        if(dp[mask]!=-1) return dp[mask];

        int set_bit = __builtin_popcount(mask);
        int opr = set_bit/2 + 1;
        int ans = 0;
       for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            for (int j = i + 1; j < n; j++) {
                if (mask & (1 << j)) continue;
                int new_mask = mask | (1 << i) | (1 << j);
                ans = max(ans, opr * gcd(nums[i], nums[j]) + f(new_mask, nums, n));
            }
        }
        return dp[mask]= ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return f(0,nums,n);
    }
};