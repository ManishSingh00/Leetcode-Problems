#define ll long long int
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll row0_sum = 0;
        ll row1_sum = 0;
        ll ans = LLONG_MAX;
        for(int i=0;i<n;i++){
            row0_sum += grid[0][i];
        }

        for(int i=0;i<n;i++){
            row0_sum -= grid[0][i];
            ans = min(ans,max(row0_sum,row1_sum));
            row1_sum += grid[1][i];
        }
        return ans;
    }
};