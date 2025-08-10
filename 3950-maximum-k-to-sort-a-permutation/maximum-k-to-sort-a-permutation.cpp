class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = -1;
        while(i<n){
            if(nums[i]!=i){
                if(ans==-1) ans = nums[i];
                else ans &= nums[i];
            }
            i++;
        }

        return ans==-1?0:ans;

    }
};