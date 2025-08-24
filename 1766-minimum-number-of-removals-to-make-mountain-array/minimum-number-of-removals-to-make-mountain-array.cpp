class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp1(n,1);
        vector<int>dp2(n,1);

        for(int i=0;i<n;i++){
            for(int prev_idx=0;prev_idx<i;prev_idx++){
                if(nums[prev_idx]<nums[i]){
                    dp1[i] = max(dp1[i], 1+dp1[prev_idx]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int prev_idx=n-1;prev_idx>i;prev_idx--){
                if(nums[prev_idx]<nums[i]){
                    dp2[i] = max(dp2[i], 1+dp2[prev_idx]);
                }
            }
        }

        int maxi = -1; // maxi is lonegst biotonic sequence
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1 )maxi = max(maxi,dp1[i]+dp2[i]-1);
        }

        return n-maxi;
    }
};