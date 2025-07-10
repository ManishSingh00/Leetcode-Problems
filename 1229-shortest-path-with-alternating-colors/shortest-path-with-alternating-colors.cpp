class Solution {
public:
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int,int>>>gr(n);

        for(int i=0;i<red.size();i++){
            gr[red[i][0]].push_back({red[i][1],1});
        }

        for(int i=0;i<blue.size();i++){
            gr[blue[i][0]].push_back({blue[i][1],0});
        }

        queue<tuple<int,int,int>>q;   //<node,len,lastedgecolor>
        q.push({0,0,-1}); 
        vector<int>ans(n,-1);
        vector<vector<bool>>vis(n,vector<bool>(2,false));
        vis[0][0] = true;
        while(q.size()>0){
            auto [node,len,clr] = q.front();
            q.pop();
            if(ans[node]==-1) ans[node] = len;

            for(auto v:gr[node]){
                if(v.second != clr && vis[v.first][v.second]==false){
                    vis[v.first][v.second] = true;
                    q.push({v.first,len+1,v.second});
                }
            }
        }
        return ans;

        
    }
};