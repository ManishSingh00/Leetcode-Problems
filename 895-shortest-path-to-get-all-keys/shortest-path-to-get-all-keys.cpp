class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int si = -1, sj = -1;

        vector<int>key(26,0);

        int key_cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    si = i, sj = j;
                }
                else if(grid[i][j]>='a' && grid[i][j]<='z'){
                    // key_cnt++;
                    key[grid[i][j]-'a'] = key_cnt++;
                }
            }
        }

        // int mask = 1<<6;
        vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(1<<key_cnt,1000)));

        dist[si][sj][0] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({si,{sj,0}});

        while(q.size()>0){
            int row = q.front().first;
            int col = q.front().second.first;
            int mask = q.front().second.second;
            q.pop();

            if(__builtin_popcount(mask) == key_cnt) return dist[row][col][mask];

            for(int i=0;i<4;i++){
                int nr = row+dx[i];
                int nc = col+dy[i];
                int nmask = mask;
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]!='#'){
                    char ch = grid[nr][nc];

                    if(ch>='a' && ch<='z'){ // found a key then, set it's bit
                        nmask |= (1<<key[ch-'a']);
                    }
                    if(ch>='A' && ch<= 'Z'){
                        if(!(nmask&(1<<key[ch-'A']))) continue; // if i do not have keys then skip that path
                    }

                    if(dist[nr][nc][nmask] > dist[row][col][mask]+1){
                        dist[nr][nc][nmask] = dist[row][col][mask]+1;
                        q.push({nr,{nc,nmask}});
                    }
                }
            }
        }   
        return -1;
    }

};