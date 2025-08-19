#define ll long long int
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll cnt = 0;
            if(nums[i] == 0){
                int j = i;
                while(j<n && nums[j]==0){
                    cnt++;
                    j++;
                }
                i = j;
                ans += (cnt*(cnt+1))/2;
            }
        }
        return ans;

    }
};