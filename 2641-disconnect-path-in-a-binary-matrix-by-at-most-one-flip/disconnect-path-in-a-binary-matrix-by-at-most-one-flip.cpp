class Solution {
public:

    bool dfs(int i,int j,vector<vector<int>>& arr,int m,int n){
        if(i>=m || j>=n || arr[i][j]==0) return false;
        if(i==m-1 && j==n-1){
            return true;
        }
        // cout<<"bug"<<endl;
        arr[i][j] = 0;

        return  dfs(i+1,j,arr,m,n) || dfs(i,j+1,arr,m,n);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(dfs(0,0,grid,m,n) == false) return true;
        grid[0][0] = 1;
        if(dfs(0,0,grid,m,n) == false) return true;

        return false;

    }
};