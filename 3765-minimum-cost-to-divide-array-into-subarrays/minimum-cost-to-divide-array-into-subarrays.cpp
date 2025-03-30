#define ll long long int
class Solution {
public:
    vector<int>pre_num;
    vector<int>pre_cost;
    ll f(ll l,ll r){
        if(l==0) return pre_cost[r];
        else return pre_cost[r]-pre_cost[l-1];
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n=nums.size();
        pre_num.resize(n);
        pre_cost.resize(n);
        pre_num[0]=nums[0],pre_cost[0]=cost[0];
        for(int i=1;i<n;i++) pre_num[i]=pre_num[i-1]+nums[i];
        for(int i=1;i<n;i++) pre_cost[i]=pre_cost[i-1]+cost[i];

        vector<ll>dp(n+1,LLONG_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                dp[i+1]=min(dp[i+1],dp[j]+pre_num[i]*(f(j,i))+(ll)k*(f(j,n-1)));
            }
        }
        return dp[n];
    }
};