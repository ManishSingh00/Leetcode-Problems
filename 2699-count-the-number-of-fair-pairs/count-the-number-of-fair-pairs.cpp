class Solution {
public:
    long long f(vector<int>& nums, int val){
        int lo = 0, hi = nums.size()-1;
        long long ans = 0;
        while(lo < hi){
            if(nums[lo] + nums[hi] < val){
                ans += (hi - lo);
                lo++;
            }
            else hi--;
        }

        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return f(nums, upper+1) - f(nums, lower);
    }
};