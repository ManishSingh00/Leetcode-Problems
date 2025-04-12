class Solution {
public:
int find(vector<int> &parent,int x){
    if(parent[x]==x) return x;
    else return parent[x]=find(parent,parent[x]);
}
void Union(vector<int> &parent,vector<int>&sz,int a,int b){
    a=find(parent,a);
    b=find(parent,b);

    if(sz[a]>=sz[b]){
        sz[a]+=sz[b];
        parent[b]=a;
    }
    else {
        sz[b]+=sz[a];
        parent[a]=b;
    }
}
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),cmp);
        // for(auto x:edges){
        //     cout<<x[0]<<x[1]<<x[2]<<" ";
        // }
        vector<int>par_a(n+1);
        vector<int>par_b(n+1);
        vector<int>sz_a(n+1,1);
        vector<int>sz_b(n+1,1);
        for(int i=1;i<=n;i++){
            par_a[i]=i;
            par_b[i]=i;
        }

        int cnt=0;
        for(int i=0;i<edges.size();i++){
            int type=edges[i][0];
            int a=edges[i][1];
            int b=edges[i][2];
            if(type==3){
                bool flag1=false,flag2=false;
                if(find(par_a,a)!=find(par_a,b)){
                    Union(par_a,sz_a,a,b);
                    flag1=true;
                }
                if(find(par_b,a)!=find(par_b,b)){
                    Union(par_b,sz_b,a,b);
                    flag2=true;
                }
                if(flag1==false && flag2==false) cnt++;
            }
            else if(type==1){
                if(find(par_a,a)==find(par_a,b)) cnt++;
                else Union(par_a,sz_a,a,b);
            }
            else{
                if(find(par_b,a)==find(par_b,b)) cnt++;
                else Union(par_b,sz_b,a,b);
            }
        }
        bool flag1=false,flag2=false;
        for(int i=1;i<=n;i++){
            if(sz_a[find(par_a,i)]==n) flag1=true;
            if(sz_b[find(par_b,i)]==n) flag2=true;
        }
        if(flag1==true && flag2==true) return cnt;
        else return -1;

    }
};