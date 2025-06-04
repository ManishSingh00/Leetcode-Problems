class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int minMoves(vector<string>& grid, int lev) {
        int m = grid.size();
        int n = grid[0].length();

        int si=-1,sj=-1;
        vector<pair<int, int>> litter_coords; 
        map<pair<int, int>, int> litter_idx_map;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='S'){
                    si = i,sj=j;
                }
                else if(grid[i][j]=='L'){
                    litter_idx_map[{i,j}] = litter_coords.size();
                    litter_coords.push_back({i,j});
                }
            }
        }

        int litter_cnt= litter_coords.size();

        static bool vis[20][20][1<<10][51];
        memset(vis,0,sizeof vis);

        
        queue<tuple<int,int,int,int,int>>q;
        q.push({si,sj,0,lev,0});
        vis[si][sj][0][lev]=true;

        while(q.size()>0){
            auto [i,j,mask,energy,step] = q.front();
            q.pop();

            if(__builtin_popcount(mask)==litter_cnt) return step;
            if(energy==0 && grid[i][j]!='R') continue;

            for(int k=0;k<4;k++){
                int nr = i+dx[k];
                int nc = j+dy[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]!='X'){
                    if(energy>0){
                        if(grid[nr][nc]=='L'){
                            int idx = litter_idx_map.at({nr,nc});
                            int new_mask = mask|(1<<idx);
                            if(vis[nr][nc][new_mask][energy-1] == false){
                                vis[nr][nc][new_mask][energy-1] = true;
                                q.push({nr,nc,new_mask,energy-1,step+1});
                            }

                        }
                        else if(grid[nr][nc]=='.' || grid[nr][nc]=='S'){
                            if(vis[nr][nc][mask][energy-1] == false){
                                vis[nr][nc][mask][energy-1] = true;
                                q.push({nr,nc,mask,energy-1,step+1});
                            }
                        }
                        else if(grid[nr][nc] == 'R'){
                            if(vis[nr][nc][mask][lev] ==false){
                                vis[nr][nc][mask][lev]=true;
                                q.push({nr,nc,mask,lev,step+1});
                            }
                        }
                    }
                }
            }
        }



        return -1;



        
    }
};