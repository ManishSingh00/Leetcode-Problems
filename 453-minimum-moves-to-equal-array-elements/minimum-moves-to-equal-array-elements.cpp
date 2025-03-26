#define ll long long int
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        ll cnt=0;
        for(auto x:nums){
            cnt+=abs((ll)nums[n-1]-(ll)x);
        }
        return cnt;
    }
};