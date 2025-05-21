class Solution {
public:
    vector<vector<int>>gr;
    vector<bool>vis;
    vector<int>ans;
    vector<int> dfs(int src,string& labels){
        vis[src]=true;
        vector<int>temp(26,0);
        temp[labels[src]-'a']=1;
        for(auto v:gr[src]){
            if(vis[v]==false){
                vector<int> arr=dfs(v,labels);
                for(int i=0;i<26;i++) temp[i]+=arr[i];
            }
        }
        ans[src] = temp[labels[src]-'a'];
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        gr.resize(n);
        ans.resize(n,0);
        vis.resize(n,false);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back(edges[i][1]);
            gr[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,labels);
        // for(auto x:dep) cout<<x<<" ";
        return ans;
    }
};