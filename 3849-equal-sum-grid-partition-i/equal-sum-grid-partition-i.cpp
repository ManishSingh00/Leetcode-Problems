class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<long long>> prefix(m, vector<long long>(n));

        prefix[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            prefix[0][i] = prefix[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){
            prefix[i][0] = prefix[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grid[i][j];
            }
        }

        long long total = prefix[m-1][n-1];

        // Check horizontal partition
        for(int i = 0; i < m - 1; i++){
            if(prefix[i][n-1] == total - prefix[i][n-1]){
                return true;
            }
        }

        // Check vertical partition
        for(int i = 0; i < n - 1; i++){
            if(prefix[m-1][i] == total - prefix[m-1][i]){
                return true;
            }
        }

        return false;
    }
};
