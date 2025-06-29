class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int,pair<int, int>>> cells;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cells.push_back({matrix[i][j],{i, j}});
            }
        }
        sort(cells.begin(), cells.end());

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = 0;
        int idx = 0;

        while (idx < cells.size()) {
            int val = cells[idx].first;

            vector<pair<int,pair<int, int>>> grp;
            while (idx < cells.size() && cells[idx].first == val) {
                grp.push_back(cells[idx]);
                idx++;
            }
           for (const auto& cell : grp) {
                int v = cell.first;
                int i = cell.second.first;
                int j = cell.second.second;
                dp[i][j] = 1 + max(row[i], col[j]);
            }

            for (const auto& cell : grp) {
                int v = cell.first;
                int i = cell.second.first;
                int j = cell.second.second;
                row[i] = max(row[i], dp[i][j]);
                col[j] = max(col[j], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
