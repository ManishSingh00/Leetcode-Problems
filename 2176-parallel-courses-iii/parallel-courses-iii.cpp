class Solution {
public:
    vector<vector<int>>gr;
    int minimumTime(int n, vector<vector<int>>& edge, vector<int>& time) {
        gr.resize(n+1);
        vector<int>indeg(n+1,0);
        for(int i=0;i<edge.size();i++){
            gr[edge[i][0]].push_back(edge[i][1]);
            indeg[edge[i][1]]++;
        }
        queue<int>q;
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
                dp[i]=time[i-1];
            }
        }
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(auto v:gr[curr]){
                dp[v]=max(dp[v],dp[curr]+time[v-1]);
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;

    }
};