class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int sum=0;
        int ans=0;
        int i=1;
        sum+=nums[0];
        while(i<n){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
                ans =max(ans,sum);
                i++;
            }
            else{
                ans = max(ans,sum);
                sum=nums[i];
                i++;
            }
        }
        return ans;
    }
};