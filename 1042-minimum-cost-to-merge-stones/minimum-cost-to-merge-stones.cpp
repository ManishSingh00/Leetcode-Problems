class Solution {
public:
    int dp[32][32];
    int f(int i,int j,vector<int>& stones,int k,vector<int>& pre){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = INT_MAX;
        for(int m=i;m<j;m+=(k-1)){
            int cost = f(i,m,stones,k,pre) + f(m+1,j,stones,k,pre);

            if((j-i)%(k-1) == 0){
                cost += pre[j+1] - pre[i];
            }
            ans = min(ans,cost);
        }

        return dp[i][j] = ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if((n-1)%(k-1)!=0) return -1;
        vector<int>pre(n+1,0);
        for(int i=1;i<n+1;i++){
            pre[i] = pre[i-1] + stones[i-1];
        }

        memset(dp,-1,sizeof dp);
        return f(0,n-1,stones,k,pre);

    }
};