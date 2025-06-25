#define ll long long int
class Solution {
public:
    ll dp[25][25];
    ll f(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        ll left = nums[i] + min(f(i+2,j,nums),f(i+1,j-1,nums));
        ll right = nums[j] + min(f(i,j-2,nums),f(i+1,j-1,nums));

        return dp[i][j] = max(left,right);  
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        ll sum = 0;
        for(auto x: nums) sum += x;
        memset(dp,-1,sizeof dp);
        ll temp = f(0,n-1,nums);
        if(sum - temp <= temp) return true;
        else return false;
    }
};