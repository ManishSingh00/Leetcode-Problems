class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_prod=nums[0],min_prod=nums[0],ans=nums[0];
        int i=1;
        while(i<n){
            int temp_max = max_prod;
            int temp_min = min_prod;

            max_prod=max(nums[i],max(temp_max*nums[i],temp_min*nums[i]));
            min_prod=min(nums[i],min(temp_max*nums[i],temp_min*nums[i]));

            ans = max(ans,max_prod);
            i++;
        }
        return ans;
    }
};