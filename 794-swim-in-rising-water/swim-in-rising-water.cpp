class Solution {
public:
    int dijkstra(vector<vector<int>>& arr,int m,int n){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        pq.push({arr[0][0],0,0}); //{wt,i,j}
        
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        dist[0][0] = arr[0][0];
        while(pq.size()>0){
            vector<int>curr=pq.top();
            pq.pop();
            int time=curr[0];
            int r=curr[1];
            int c=curr[2];
            if(r==m-1 && c==n-1) return time;
            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int newt=max(time,arr[nr][nc]);
                    if(newt<dist[nr][nc]){
                        dist[nr][nc]=newt;
                        pq.push({newt,nr,nc});
                    }
                }
            }
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return dijkstra(grid,m,n);
    }
};