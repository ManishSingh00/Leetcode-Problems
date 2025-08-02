class Solution {
public:

    // bool vis[1<<20];
    int empty=0;

    int f(int i,int j,vector<vector<int>>& grid,int ei,int ej,int m,int n,int mask){
        if(i<0 || j <0 || i>=m || j>= n || grid[i][j]==-1) return 0;

        // if(vis[1<<(i*j)] == false) vis[1<<(i*j)] = true;
        if((mask&(1<<(i*n+j)))) return 0;

        mask |= (1<<(i*n+j));

        if(i==ei && j== ej){
            if(__builtin_popcount(mask)==empty){
                return 1;
            }
            else return 0;
        }

        int ans = 0;
        ans += f(i+1,j,grid,ei,ej,m,n, mask);
        // mask &= ~(1<<((i+1)*j));

        ans += f(i,j+1,grid,ei,ej,m,n, mask);
        // mask &= ~(1<<(i*(j+1)));

        ans += f(i-1,j,grid,ei,ej,m,n, mask);
        // mask &= ~(1<<((i-1)*j));

        ans += f(i,j-1,grid,ei,ej,m,n, mask);
        // mask &= ~(1<<(i*(j-1)));

        return ans;


    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int si,sj,ei,ej;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    si = i, sj = j;
                }
                if(grid[i][j]==2){
                    ei = i, ej = j;
                } 
                if(grid[i][j] != -1)
                empty++;
            }
        }
        // memset(vis,false,sizeof vis);
        return f(si,sj,grid,ei,ej,m,n,0);


    }
};