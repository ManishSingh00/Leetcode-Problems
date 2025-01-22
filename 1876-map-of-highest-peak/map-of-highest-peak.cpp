class Solution {
public:
    vector<int>dx = {-1,1,0,0};
    vector<int>dy = {0,0,1,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vector<vector<int>>ans(m,vector<int>(n,0));

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) q.push({i,j});
            }
        }
        while(q.size()>0){
            auto x = q.front();
            q.pop();
            int r = x.first;
            int c = x.second;
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && arr[nr][nc]==0){
                    ans[nr][nc] = 1 + ans[r][c];
                    q.push({nr,nc});
                    arr[nr][nc]=1;
                } 
            }
        }

        return ans;
    }
};