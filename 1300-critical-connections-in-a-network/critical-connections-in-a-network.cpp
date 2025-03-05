class Solution {
public:
    vector<list<int>>gr;
    vector<vector<int>>ans;
    vector<int>tin;
    vector<int>low;
    unordered_set<int>vis;
    int time=1;
    void dfs(int src,int par){
        vis.insert(src);
        low[src]=tin[src]=time;
        time++;
        for(auto v:gr[src]){
            if(v==par) continue;
            if(vis.count(v)==0){
                dfs(v,src);
                low[src]=min(low[src],low[v]);

                if(low[v] > tin[src]){
                    ans.push_back({src,v});
                }
            }
            else{
                low[src]=min(low[src],low[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        gr.resize(n+1);
        tin.resize(n+1);
        low.resize(n+1);
        for(int i=0;i<connections.size();i++){
            gr[connections[i][0]].push_back(connections[i][1]);
            gr[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0,-1);
        return ans;
    }
};