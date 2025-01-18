#define pp pair<int,pair<int,int>>
class Solution {
public:
    int m,n;
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    int f(vector<vector<int>>& grid){
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,{0,0}});
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        // vis[0][0]=true;

        while(pq.size()>0){
            auto x = pq.top();
            pq.pop();
            int cost = x.first;
            int r = x.second.first;
            int c = x.second.second;
            if (vis[r][c]) continue; // Avoid revisiting
            vis[r][c] = true;

            if(r==m-1 && c==n-1) return cost;
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && vis[nr][nc]==false){
                    if(i+1==grid[r][c]){
                        pq.push({cost,{nr,nc}});
                        // vis[nr][nc]=true;
                    }
                    else{
                        pq.push({cost+1,{nr,nc}});
                        // vis[nr][nc]=true;
                    }
                }
            }

        }
        return 0;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return f(grid);
    }
};