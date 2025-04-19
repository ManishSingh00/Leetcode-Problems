class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        vector<int>indeg(n,0);
        vector<vector<int>>gr(n);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(q.size()>0){
            auto curr=q.front();
            q.pop();
            for(auto v:gr[curr]){
                set<int>st;
                indeg[v]--;
                for(auto x:ans[curr]){
                    st.insert(x);
                }
                st.insert(curr);
                for(auto x:st) ans[v].insert(x);

                if(indeg[v]==0) q.push(v);
            }
        }
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++){
            for(auto x:ans[i]){
                arr[i].push_back(x);
            }
        }
        return arr;
    }
};