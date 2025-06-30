class Solution {
public:
    vector<int>par;
    vector<int>sz;
    int components;
    int find(int x){
        if(par[x]==x) return par[x];
        return par[x]= find(par[x]);
    }
    void Union(int a,int b){
        a = find(a), b = find(b);
        if(a!=b) components--;
        if(sz[a]>= sz[b]){
            par[b] = a;
            sz[a]+=sz[b];
        }
        else{
            par[a]=b;
            sz[b]+=sz[a];
        }
    }
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]>b[2];
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        cout<<"hello";
        par.resize(n);
        sz.resize(n,1);
        components = n;
        for(int i=0;i<n;i++) par[i] = i;
        int mini = INT_MAX;
        for(auto& edge:edges){
            int a = edge[0];
            int b = edge[1];
            int str = edge[2];
            int must = edge[3];
            if(must == 1){
               
                if(find(a)==find(b)) return -1;
                else{
                    Union(a,b);
                    mini = min(mini,str);
                }
            }
        }
        cout<<"hello";
        sort(edges.begin(),edges.end(),cmp);
        vector<int>vals;
         for(auto& edge:edges){
            int a = edge[0];
            int b = edge[1];
            int str = edge[2];
            int must = edge[3];
             if(must == 0){
                 if(find(a)==find(b)) continue;
                 else{
                    Union(a,b);
                    vals.push_back(str);
                 }
             }
        }

        if (components > 1) return -1;
        sort(vals.begin(),vals.end());
        for(int i=0;i<min(k,(int)vals.size());i++){
            vals[i]*=2;
        }
        int  mini2 = INT_MAX;
        if(vals.size()>0) mini2= *min_element(vals.begin(),vals.end());
        return min(mini,mini2);
    }
};