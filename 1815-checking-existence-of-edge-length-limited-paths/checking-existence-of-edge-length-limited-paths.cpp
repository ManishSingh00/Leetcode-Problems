class Solution {
public:
    vector<int>par;
    vector<int>size;
    int find(int x){
        if(par[x]==x) return x;
        else return par[x]=find(par[x]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(size[a]>= size[b]){
            par[b] = a;
            size[a]+=size[b];
        }
        else{
            par[a]=b;
            size[b]+=size[a];
        }
    }
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        par.resize(n);
        size.resize(n,0);
        for(int i=0;i<n;i++) par[i]= i;
        // cout<<"hello";
        int m = edges.size();
        int sz = q.size();
        // int i = 0;
        for(int i=0;i<sz;i++){
            q[i].push_back(i);
        }
        // cout<<q[0][3]<<endl;
        // cout<<"hello";
        sort(edges.begin(),edges.end(),cmp);
        sort(q.begin(),q.end(),cmp);

        vector<bool>ans(sz);
        int edge_idx=0;
        int q_idx = 0;
        while(q_idx < sz){
            int limit= q[q_idx][2];
            while(edge_idx < m && edges[edge_idx][2]<limit){
                Union(edges[edge_idx][0],edges[edge_idx][1]);
                edge_idx++;
            }
            // cout<<q[q_idx][3]<<" ";
            cout<<find(q[q_idx][0])<<" "<<find(q[q_idx][1]);
            if(find(q[q_idx][0]) == find(q[q_idx][1])) ans[q[q_idx][3]] = true;
            else ans[q[q_idx][3]] = false;
            q_idx++;
        }

        return ans;

    }
};