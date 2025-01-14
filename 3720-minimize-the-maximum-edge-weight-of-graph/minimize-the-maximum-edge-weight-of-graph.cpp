class Solution {
public:

    bool f(vector<vector<int>>& edges,int n,int wt){
        vector<vector<int>>gr(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i][2]<=wt){
                gr[edges[i][1]].push_back(edges[i][0]);
            }
        }

        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int node=q.front();
            q.pop();
            for(auto x:gr[node]){
                if(vis[x]==true) continue;
                vis[x]=true;
                q.push(x);
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]==false) return false;
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int lo=0,hi=1e6;
        int ans=-1;

        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(f(edges,n,mid)==true){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};