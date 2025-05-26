class Solution {
public:
    vector<vector<int>>gr;
    vector<int>indeg;
    int dp[1<<22];
    int f(int mask,vector<int>& score,int n){
        if(__builtin_popcount(mask)==n) return 0;  // OR if(mask==(1<<n)-1) return  0;
        if(dp[mask]!=-1) return dp[mask];

        int cnt = __builtin_popcount(mask)+1;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i)) && indeg[i]==0){
                for(auto& v:gr[i]){
                    indeg[v]--;
                }
                ans = max(ans,score[i]*cnt+f(mask|(1<<i),score,n));

                for(auto& v:gr[i]){
                    indeg[v]++; // kind of backtrack to explore other possibility
                }
            }
        }
        return dp[mask]=ans;
    }
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        gr.resize(n);
        indeg.resize(n,0);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0],b = edges[i][1];
            gr[a].push_back(b);
            indeg[b]++;
        }
        return f(0,score,n);
    }
};