#define ll long long int
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid;
        if(n%2==0) mid=n/2-1;
        else mid=n/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            ll diff=abs(nums[mid]-nums[i]);
            cnt+=diff;
        }
        return cnt;
    }
};