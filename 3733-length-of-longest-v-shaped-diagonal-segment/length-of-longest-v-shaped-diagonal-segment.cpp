class Solution {
public:
    int dx[4] = {-1,1,1,-1};
    int dy[4] = {1,1,-1,-1};
    int dp[505][505][5][2];
    
    
    int f(int i,int j,int curr_dir,bool can_change,int n,int m,vector<vector<int>>& grid){
        if(dp[i][j][curr_dir][can_change] != -1) return dp[i][j][curr_dir][can_change];
        
        int next_element = grid[i][j]==2?0:2;
        int ans = 0;
        int x = i+dx[curr_dir] , y = j + dy[curr_dir];

        if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == next_element){
            ans = max(ans, 1+ f(x,y,curr_dir,can_change,n,m,grid));
        }

        if(can_change == true){
            int new_dir = (curr_dir + 1) %4;
            int x = i+dx[new_dir] , y = j+dy[new_dir];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == next_element){
                ans = max(ans, 1+ f(x,y,new_dir,false,n,m,grid));
            }
        }

        return dp[i][j][curr_dir][can_change] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof dp);

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    for(int k = 0;k<4;k++){
                        ans = max(ans,1 + f(i,j,k,true,n,m,grid));
                    }
                }
            }
        }

        return ans;

    }
};