class Solution {
public:
    unordered_map<int,int>mp;
    int dp[2005][2005];
    int n;
    int f(int i,int k,vector<int>& arr){
        if(i>=n) return 0;
        if(i==n-1) return 1;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=0;
        for(int j=k-1;j<=k+1;j++){
            if(j==0) continue;
            if(mp.find(arr[i]+j)!=mp.end()){
                ans = ans || f(mp[arr[i]+j],j,arr);
            }
        }
        return dp[i][k]=ans;

    }
    bool canCross(vector<int>& arr) {
        n = arr.size();
        if(arr[1]!=1) return false;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++){
            mp[arr[i]]=i;
        }
        return f(1,1,arr);

    }
};