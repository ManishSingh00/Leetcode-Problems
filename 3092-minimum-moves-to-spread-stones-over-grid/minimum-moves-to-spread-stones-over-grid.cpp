class Solution {
public:
    int f(int i,vector<pair<int,int>>& empty,vector<pair<int,int>>& filled,vector<vector<int>>& grid){
        if(i>=empty.size()) return 0;
        int ans = 1e5;

        for(int j=0;j<filled.size();j++){
            int r = filled[j].first;
            int c = filled[j].second;
            if(grid[r][c]>1){
                grid[r][c]--;
                ans = min(ans,abs(r-empty[i].first)+abs(c-empty[i].second)+f(i+1,empty,filled,grid));
                grid[r][c]++;
            }
        }

        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>>empty;
        vector<pair<int,int>>filled;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0) empty.push_back({i,j});
                else if(grid[i][j]>1) filled.push_back({i,j});
            }
        }
        if(empty.size() == 0) return 0;
        return f(0,empty,filled,grid);
    }
};