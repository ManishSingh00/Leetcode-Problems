class Solution {
public: 
    int f(vector<int> nums,int n,int len1,int len2){
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<len1;i++) sum1 += nums[i];
        for(int i=len1;i<len1+len2;i++) sum2 += nums[i];

        int max1 = sum1, max2 = sum2;
        int ans = max1+sum2;
        for(int i =len1+len2;i<n;i++){
            sum1 += (nums[i-len2] - nums[i-len2-len1]);
            sum2 += nums[i] - nums[i-len2];

            max1 = max(max1,sum1);
            // max2 = max(max2,sum2);

            ans = max(ans,max1+sum2);
        }

        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int first, int second) {
        int n = nums.size();
        return max(f(nums,n,first,second), f(nums,n,second,first));
    }
};