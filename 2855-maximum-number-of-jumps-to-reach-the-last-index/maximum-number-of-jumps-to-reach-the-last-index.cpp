#define ll long long int
class Solution {
public:
    int n;
    ll dp[1005];
    ll f(int i,int tar,vector<int>& nums){
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        ll ans=LLONG_MIN;
        for(int j=i+1;j<n;j++){
            if(abs(nums[i]-nums[j])<=tar){
                ans=max(ans,1+f(j,tar,nums));
            }
        }
        // if(ans<=0) return dp[i]=-1;
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int tar) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        ll ans = f(0,tar,nums);
        cout<<ans<<endl;
        // if(ans==0) return -1;?
        if(ans<0) return -1;
        return ans;
    }
};