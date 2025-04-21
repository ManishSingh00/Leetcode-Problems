class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int maxi = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<maxi){
                ans++;
            }
            else maxi=max(maxi,nums[i]);
        }
        return n-ans;
    }
};