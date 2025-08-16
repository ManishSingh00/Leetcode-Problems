#define ll long long int
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        ll ans = 0;
        for(int i=n-2;i>=0;i--){
            int steps = (nums[i]-1)/last;
            last = nums[i]/(steps+1);
            ans += steps;
        }

        return ans;
    }
};