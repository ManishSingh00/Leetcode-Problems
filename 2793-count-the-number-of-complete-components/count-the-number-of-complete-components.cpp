class Solution {
public:
    vector<list<int>>gr;
    unordered_set<int>vis;
    vector<pair<int,int>>cnt;
    void dfs(int src,int& cnt_node,int& cnt_edge){
        vis.insert(src);
        cnt_node++;
        for(auto v:gr[src]){
            cnt_edge++;
            if(vis.count(v)==0){
                dfs(v,cnt_node,cnt_edge);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        gr.resize(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            int cnt_node=0,cnt_edge=0;
            if(vis.count(i)==0){
                dfs(i,cnt_node,cnt_edge);
                cnt.push_back({cnt_node,cnt_edge/2});
            }
        }

        int ans=0;
        for(int i=0;i<cnt.size();i++){
            int node=cnt[i].first,edge=cnt[i].second;
            // if(node == 1) ans++;
            if(((node*(node-1))/2) == edge) ans++;
        }

        return ans;
    }
};