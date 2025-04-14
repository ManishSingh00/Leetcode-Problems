class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int k=n-1;k>=0;k--){
            if(k<n-1 && nums[k]==nums[k+1]) continue;
            int i=0,j=k-1;

            while(i<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    cnt++;
                    ans.push_back({nums[i],nums[j],nums[k]});
                    i++;
                    j--;
                    while(i<j && nums[i]==nums[i-1]) i++;
                    while(i<j && nums[j]==nums[j+1]) j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0) j--;
                else i++;
            }
        }
        return ans;
    }
};