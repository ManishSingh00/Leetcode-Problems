class Solution {
public:
    int n, m;
    vector<vector<int>> time;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool f(int mid) {
        queue<tuple<int, int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;
        q.push({mid, 0, 0});

        while(!q.empty()){
            auto [t, r, c] = q.front();
            q.pop();
            // Allow reaching safehouse at the same time as fire
            if(r == n - 1 && c == m - 1 && t <= time[r][c]) return true;
            if(time[r][c] <= t) continue;
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && 
                   visited[nr][nc] == 0 && time[nr][nc] > t ){
                    q.push({t + 1, nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        return false;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        time.resize(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    time[i][j] = 0;
                }
                else if(grid[i][j] == 2) {
                    time[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && 
                   grid[nr][nc] == 0 && time[nr][nc] == 1e9){
                    time[nr][nc] = 1 + time[r][c];
                    q.push({nr, nc});
                }
            }
        }
        int lo = 0, hi = n * m;
        int mid;
        int ans = -1;
        while(lo <= hi){
            mid = lo+(hi-lo) / 2;
            if(f(mid)){
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
       return f(1e5) ? 1e9 : ans;
    }
};
