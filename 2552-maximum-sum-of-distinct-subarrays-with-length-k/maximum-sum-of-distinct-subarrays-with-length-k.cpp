class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int distinct = 0;
        int l=0,r=k-1;
        long long int sum = 0;
        long long int ans = 0;
        vector<int>freq(100005,0);
        for(int i=0;i<=r;i++){
            freq[nums[i]]++;
            sum+=nums[i];
            if(freq[nums[i]]==1) distinct++;
        }
        if(distinct == k) ans = max(ans,sum);

        while(r<n-1){
            freq[nums[l]]--;
            if(freq[nums[l]]==0) distinct--;
            sum -= nums[l];
            l++;

            freq[nums[r+1]]++;
            if(freq[nums[r+1]]==1) distinct++;
            sum+=nums[r+1];
            if(distinct == k) ans = max(ans,sum);
            r++;

        }

        return ans;

    }
};