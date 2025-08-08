class Solution {
public:
    int m,n;
    vector <int> par;
    vector <int> size;
    
    int find(int x){
        if (par[x]!=x) par[x]=find(par[x]);
        return par[x];
    }
    
    void Union(int x,int y){
        int r1=find(x);
        int r2=find(y);
        if (r1==r2) return;
        if (size[r1]>=size[r2]){
            par[r2]=r1;
            size[r1]+=size[r2];
        }
        else{
            par[r1]=r2;
            size[r2]+=size[r1];
        }
    }

    void modified_union(int i,int j,vector<vector<int>>& grid){
        int idx=i*n+j+1;
        vector <pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0}};
        for (auto &d: dir){
            int ni=i+d.first,nj=j+d.second;
            if (ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                int new_idx=ni*n+nj+1;
                Union(idx,new_idx);
            }
        }
        if(i == 0) Union(0,idx);
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m=grid.size();
        n=grid[0].size();
        int cnt=hits.size();

        size.resize(m*n+1,1);
        size[0]=0;

        par.resize(m*n+1,0);
        for (int i=0;i<m*n+1;i++) par[i]=i;
    
        vector <int> ans(cnt,0);

        for (auto &it: hits){
            int x=it[0],y=it[1];
            if (grid[x][y]==1) grid[x][y]=-1;
        }

        for (int i=0;i<m;i++){
            for (int j=0; j<n;j++){
                if (grid[i][j]==1) modified_union(i,j,grid);
            }
        }
        int curr_sz=size[find(0)];
        for(int i=cnt-1;i>=0;i--){
            int x = hits[i][0], y = hits[i][1];
            if(grid[x][y] == -1){
                grid[x][y] = 1;
                modified_union(x,y,grid);
                int new_sz = size[find(0)];
                if(new_sz>curr_sz) ans[i] = new_sz - curr_sz - 1;

                curr_sz = new_sz;
            }
        }
        return ans;
    }
};