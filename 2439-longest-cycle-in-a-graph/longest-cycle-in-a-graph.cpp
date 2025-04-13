class Solution {
public:
    vector<list<int>>gr;
    vector<int> state;
    vector<int>dist;
    int ans;
    void dfs(int node,vector<int>& dist){
        state[node]=1;
        for(auto v:gr[node]){
            if(state[v]==0){
                dist[v]=dist[node]+1;
                dfs(v,dist);
            }
            else if(state[v]==1){
                ans=max(ans,dist[node]-dist[v]+1);
            }
        }
        state[node]=2;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        gr.resize(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) gr[i].push_back(edges[i]);
        }
        state.resize(n, 0);
        dist.resize(n,0);
        ans=-1;
        for(int i=0;i<n;i++){
            if(state[i]==0){
                dist[i]=1;
                dfs(i,dist);
            }
        }
        return ans;
        
    }
};