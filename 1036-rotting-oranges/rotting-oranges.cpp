class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){ 
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time= 0;
        while(q.size()>0){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int nr = r+dx[k];
                    int nc = c+dy[k];
                    if(nr<0 || nc<0 || nr>=m || nc>=n || grid[nr][nc] == 0 || grid[nr][nc] == 2) continue;
                    if(grid[nr][nc] == 1){
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
            if(q.size()>0) time++; // only increase time if new oranggs are added
        }

         for(int i=0;i<m;i++){ 
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};