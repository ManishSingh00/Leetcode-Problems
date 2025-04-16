class Solution {
public:
    vector<list<int>>gr;
    unordered_set<int>vis;
    void dfs(int node){
        vis.insert(node);
        for(auto v:gr[node]){
            if(vis.count(v)==0) dfs(v);
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        gr.resize(n);
        vector<int>indeg(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            gr[a].push_back(b);
            indeg[b]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            // if(vis.count(i)==0){
            //     // vis.insert(i);
            //     ans.push_back(i);
            //     dfs(i);
            // }
            if(indeg[i]==0) ans.push_back(i);
        }
        return ans;
    }
};