class Solution {
public:
    int dp[100005];
    int f(int i,vector<int>& pref,int n){
        if(i == n-1) return pref[n-1];
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;

        ans = pref[i] - f(i+1,pref,n); // alice stop and bob starts and trying to minimize the score
        ans = max(ans, f(i+1,pref,n)); // bob will continue taking  the stone

        return dp[i] = ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>pref(n,0);
        pref[0] = stones[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + stones[i];
        }

        memset(dp,-1,sizeof dp);
        return f(1,pref,n);

    }
};