#define ll long long int
class Solution {
public:
    vector<vector<int>> mat;
    ll dp[72][72][72];
    ll m,n;
    ll f(ll i,ll j,ll y){
        if(i<0 || j<0 || y<0 || i>=m || j>=n || y>=n ) return INT_MIN;
        if (i == m - 1) {
            if (j == y) return mat[i][j];
            else return mat[i][j] + mat[i][y];
        }
        if(dp[i][j][y]!=-1) return dp[i][j][y];
        ll result=INT_MIN;

        for(int t1=-1;t1<=1;t1++){
            for(int t2=-1;t2<=1;t2++){
                if(j != y) result = max(result,mat[i][j] + mat[i][y] + f(i+1,j+t1,y+t2));
                else result = max(result,mat[i][j] + f(i+1,j+t1,y+t2));
            }
        }

        return dp[i][j][y]=result;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        mat=grid;
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof dp);
        ll ans=f(0,0,n-1);
        if(ans==INT_MIN) return 0;
        else return ans;
    }
};