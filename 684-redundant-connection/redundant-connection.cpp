class Solution {
public:
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

    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }  
        for(int i=0;i<n;i++){
            int a=edges[i][0]-1;
            int b=edges[i][1]-1;
            if(Union(a,b)==true) continue;
            else{
                return {a+1,b+1};
            }
        }
        return {};     
    }
};