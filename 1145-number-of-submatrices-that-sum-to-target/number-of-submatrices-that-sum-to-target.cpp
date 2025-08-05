class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int tar) {
        int m= matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m,vector<int>(n));
        mat[0][0] = matrix[0][0];
        for(int j=1;j<n;j++){
            mat[0][j] = matrix[0][j] + mat[0][j-1];
        }

        for(int i=1;i<m;i++){
            mat[i][0] = matrix[i][0] + mat[i-1][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j] = matrix[i][j] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }

        int cnt = 0;

        for (int r1 = 0; r1 < m; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = r1; r2 < m; r2++) {
                    for (int c2 = c1; c2 < n; c2++) {
                        int sum = mat[r2][c2];
                        if (r1 > 0) sum -= mat[r1 - 1][c2];
                        if (c1 > 0) sum -= mat[r2][c1 - 1];
                        if (r1 > 0 && c1 > 0) sum += mat[r1 - 1][c1 - 1];

                        if (sum == tar) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};