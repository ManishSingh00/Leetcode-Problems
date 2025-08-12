class Solution {
public:
    vector<int>par;
    vector<int>rank;

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void Union(int x,int y){
        int r1=find(x);
        int r2=find(y);
        if (r1==r2) return;
        if (rank[r1]>=rank[r2]){
            par[r2]=r1;
            rank[r1]+=rank[r2];
        }
        else{
            par[r1]=r2;
            rank[r2]+=rank[r1];
        }
    }

    vector<bool> areConnected(int n, int thr, vector<vector<int>>& q) {
        int sz = q.size();
        vector<bool>ans(sz);
        par.resize(n+1,0);
        rank.resize(n+1,0);

        for(int i=1;i<=n;i++) par[i] = i;

        for(int i=thr+1;i<n;i++){
            int j = 1;
            while(i*j<=n){
                Union(i,i*j);
                j++;
            }
        }

        for(int i=0;i<sz;i++){
            int a = q[i][0], b=q[i][1];
            if(find(a)==find(b)) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};