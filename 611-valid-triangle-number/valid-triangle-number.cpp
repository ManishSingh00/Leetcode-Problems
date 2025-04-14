class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int k=n-1;k>=0;k--){
            int i=0,j=k-1;

            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    cnt+=(j-i);
                    j--;
                }
                else i++;
            }
        }
        return cnt;
    }
};