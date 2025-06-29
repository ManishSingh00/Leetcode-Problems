#define mod 1000000007
class Solution {
public:
 
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i = 0 ,j =n-1;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2) % mod;
        }
        while(i<=j){
           if(nums[i]+nums[j]<= target){
                // int x = pow(2,j-i);
                ans = (ans + power[j-i])%mod;
                i++;
           }
           else j--;
        }

        return ans;
    }
};