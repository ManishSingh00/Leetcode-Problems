class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(),nums.end());

        int mx = 0;
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i]-nums[i-1]==1){
                cnt++;
            }
            else {
                mx = max(mx,cnt);
                cnt = 1;
            }
        }
        mx = max(mx,cnt);
        return mx;
    }
};