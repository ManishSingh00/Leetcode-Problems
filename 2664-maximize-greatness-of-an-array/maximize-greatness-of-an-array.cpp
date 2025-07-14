class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0;
        int ans = 0;
        sort(nums.begin(),nums.end());
        while(j<n){
            if(i<n && nums[i]<nums[j]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};