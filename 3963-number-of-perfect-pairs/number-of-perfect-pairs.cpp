#define ll long long int
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] < 0) nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        ll ans = 0;
        int left = 0, right = 1;
        while(right < n){
            while(right<n && nums[right] <= 2*nums[left]){
                right++;
                ans += (right - left - 1);
            }
            left++;
        }

        return ans;
    }
};