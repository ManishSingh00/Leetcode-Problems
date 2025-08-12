class Solution {
public:
    int dp[505][505];
    int f(int i,int j,vector<int>& pre){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MIN;

        for(int k=i;k<=j;k++){
            int left = pre[k] - (i==0?0:pre[i-1]);
            int right = pre[j] - pre[k];

            if(left>right)  ans = max(ans,right + f(k+1,j,pre));
            else if(left<right) ans = max(ans,left+f(i,k,pre));
            else ans = max({ans,right+f(k+1,j,pre),left+f(i,k,pre)});
        }

        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stone) {
        int n = stone.size();
        vector<int>pre(n);
        pre[0] = stone[0];
        for(int i=1;i<n;i++){
            pre[i] = stone[i] + pre[i-1];
        }

        memset(dp,-1,sizeof dp);
        return f(0,n-1,pre);
    }
};