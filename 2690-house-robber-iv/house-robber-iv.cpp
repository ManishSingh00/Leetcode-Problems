class Solution {
public:
    bool f(vector<int>& nums,int mid,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                cnt++;
                i++;  // we cannot pick consecutive
            }
        }
        if(cnt>=k) return true;
        else return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int lo=*min_element(nums.begin(),nums.end());
        int hi=*max_element(nums.begin(),nums.end());
        int mid;
        int ans;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(f(nums,mid,k)==true){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};