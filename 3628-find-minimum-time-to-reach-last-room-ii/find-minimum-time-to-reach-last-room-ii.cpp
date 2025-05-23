#define ll long long
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int minTimeToReach(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>>dist(n,vector<long long>(m,LLONG_MAX));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;
        dist[0][0] = 0;
        pq.emplace(0LL, 0, 0);
        while(pq.size()>0){
            auto [t, x, y] = pq.top();
            pq.pop();
            if (t > dist[x][y]) continue;
            if(x==n-1 && y==m-1) return (int)t;

            for(int k=0;k<4;k++){
                int nr = x+dx[k];
                int nc = y+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int waiting_time=max(0,grid[nr][nc]-(int)t);
                    int new_time = t+waiting_time;
                    if((x+y)%2==0) new_time+=1;
                    else new_time+=2;
                    if(new_time<dist[nr][nc]){
                        dist[nr][nc]=new_time;
                        pq.push({new_time,nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};