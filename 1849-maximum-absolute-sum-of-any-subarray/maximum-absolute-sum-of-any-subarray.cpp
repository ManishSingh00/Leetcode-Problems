class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int ans1=0;
        int i=0;
        while(i<n){
            sum+=nums[i];
            ans1=max(ans1,sum);
            if(sum<0){
                sum=0;
            }
            i++;
        }
        sum=0;
        int ans2=0;
        i=0;
        while(i<n){
            sum+=nums[i];
            ans2=min(sum,ans2);
            if(sum>0){
                sum=0;
            }
            i++;
        }
        return max(ans1,abs(ans2));

    }
};