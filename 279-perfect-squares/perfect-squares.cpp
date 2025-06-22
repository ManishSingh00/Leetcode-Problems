class Solution {
public:
    vector<int>arr;
    int dp[105][10005];
    int f(int i,int sz,int n){
        if(i==sz) return 1e5;
        if(n==0) return 0;

        if(dp[i][n]!=-1) return dp[i][n];
        int ans = f(i+1,sz,n);
        if(n-arr[i] >= 0) ans = min(ans ,1+f(i,sz,n-arr[i]));
        if(n-arr[i] >= 0)ans = min(ans,1+f(i+1,sz,n-arr[i]));

        return dp[i][n] = ans;
    }
    int numSquares(int n) {
        for(int i=1;i<=sqrt(n);i++) arr.push_back(i*i);
        memset(dp,-1,sizeof dp);
        int sz = arr.size();
        return f(0,sz,n);
    }
};