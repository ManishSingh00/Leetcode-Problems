class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        bool min_f=false,max_f=false;
        int min_s=0,max_s=0;
        int x=0;
        long long  ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                min_f=false;
                max_f=false;
                x=i+1;
            }
            if(nums[i]==minK){
                min_f=true;
                min_s=i;
            }
            if(nums[i]==maxK){
                max_f = true;
                max_s = i;
            }

            if(min_f==true && max_f == true){
                ans += min(min_s,max_s) - x+1;
            }
        }
        return ans;


    }
};