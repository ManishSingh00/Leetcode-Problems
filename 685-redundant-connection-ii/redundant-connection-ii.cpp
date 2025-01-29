class Solution {
public:
    vector<int>indeg;
    vector<int>par;
    vector<int>sz;
    int find_par(int x){
        if(par[x]==x) return x;
        return par[x]=find_par(par[x]);
    }
    bool Union(int a,int b){
        a = find_par(a);
        b = find_par(b);
        if(a==b) return false;
        if(sz[a]>=sz[b]){
            sz[a]+=sz[b];
            par[b]=a;
        }
        else{
            sz[b]+=sz[a];
            par[a]=b;
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        indeg.resize(n+1,0);

        vector<int>first,second;
        for(int i=0;i<n;i++){
            int x=edges[i][0],y=edges[i][1];
            if(indeg[y]==0) indeg[y]=x;
            else{
                first = {indeg[y],y};
                second = {x,y};
                edges[i][1]=0;
            }
        }

        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }  

        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(b==0) continue;
            if(Union(a,b)==true) continue;
            else{
                if(first.size()>0) return first;
                else return {a,b};
            }
        }
        return second;     
    }   
};