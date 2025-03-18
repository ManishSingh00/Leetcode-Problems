#define ll long long int
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int i=0,j=1;
        int ans=1;
        ll sum=nums[0];
        while(j<n){
            while((sum&nums[j])!=0){
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};