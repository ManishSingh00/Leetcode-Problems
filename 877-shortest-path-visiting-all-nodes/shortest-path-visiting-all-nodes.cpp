class Solution {
public:
    bool vis[13][1<<13];
    int shortestPathLength(vector<vector<int>>& gr) {
        int n = gr.size();
        memset(vis,false,sizeof vis);
        
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,1<<i,0});
            vis[i][1<<i]=true;
        }

        while(q.size()>0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [src,mask,step] = q.front(); 
                q.pop();
                if(__builtin_popcount(mask)==n){
                    return step;
                }
                for(auto v:gr[src]){
                    int new_mask = mask|(1<<v);
                    if(vis[v][new_mask]==false){
                        vis[v][new_mask]= true;
                        q.push({v,new_mask,step+1});
                    }
                }
            }
        }
        return -1;
    }
};
