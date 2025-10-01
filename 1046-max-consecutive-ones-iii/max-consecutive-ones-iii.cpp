class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r= 0;
        int ans = 0;
        while(r<n){
            if(nums[r] == 1) r++;
            else if(nums[r] == 0){
                if(k>0){
                    k--;
                    r++;
                }
                else{
                    ans = max(ans,r-l);
                    while(nums[l] != 0) l++;
                    l++;
                    k++;
                }
            }
        }
        ans = max(ans,r-l);
        return ans;
    }
};