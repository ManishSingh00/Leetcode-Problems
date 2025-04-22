class Solution {
public:
    vector<vector<pair<int,int>>>gr;
    vector<int>vis;
    
    int ans=0;
    void dfs(int src,int time,int maxTime,vector<int>& values,int curr_val){
        if(time>maxTime) return;
        if(vis[src]==0) curr_val+=values[src];
        vis[src]++;

        if(src==0) ans = max(ans,curr_val);

        for(auto v:gr[src]){
            dfs(v.first,time+v.second,maxTime,values,curr_val);
        }
        vis[src]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int m = edges.size();
        gr.resize(n);
        vis.resize(n,0);
        for(int i=0;i<m;i++){
            int a=edges[i][0],b=edges[i][1],
            wt=edges[i][2];
            gr[a].push_back({b,wt});
            gr[b].push_back({a,wt});
        }
        dfs(0,0,maxTime,values,0);
        return ans;

    }
};