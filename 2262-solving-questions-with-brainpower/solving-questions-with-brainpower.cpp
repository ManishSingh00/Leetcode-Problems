#define ll long long int
class Solution {
public:
    int n;
    ll dp[100005];
    ll f(int i,vector<vector<int>>& arr){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        ll ans=f(i+1,arr);
        ans = max(ans, arr[i][0]+f(i+1+arr[i][1],arr));
        return dp[i]=ans;
    }
    long long mostPoints(vector<vector<int>>& arr) {
        memset(dp,-1,sizeof(dp));
        n=arr.size();
        return f(0,arr);
    }
};