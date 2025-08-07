#define ll long long int
class Solution {
public:
    ll dp[1005][1005];
    ll f2(int i,int j,int n,vector<vector<int>>& arr){
        if(i<0 || j<0 || i>=n || j>=n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans = LLONG_MIN;

        if(i==j){
            ans = max(ans,f2(i+1,j+1,n,arr));
        }
        else if(i == j-1){
            ans = max(ans,arr[i][j] + f2(i+1,j+1,n,arr));
            ans = max(ans, arr[i][j] + f2(i+1,j,n,arr));
        }
        else{
            ans = max(ans,arr[i][j] + f2(i+1,j-1,n,arr));
            ans = max(ans,arr[i][j] + f2(i+1,j,n,arr));
            ans = max(ans,arr[i][j] + f2(i+1,j+1,n,arr));
        }

        return dp[i][j] = ans;
    }
    ll f3(int i,int j,int n,vector<vector<int>>& arr){
        if(i<0 || j<0 || i>=n || j>=n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans = LLONG_MIN;

        if(i==j){
            ans = max(ans,f3(i+1,j+1,n,arr));
        }
        else if(i-1 == j){
            ans = max(ans,arr[i][j] + f3(i,j+1,n,arr));
            ans = max(ans, arr[i][j] + f3(i+1,j+1,n,arr));
        }
        else{
            ans = max(ans,arr[i][j] + f3(i-1,j+1,n,arr));
            ans = max(ans,arr[i][j] + f3(i,j+1,n,arr));
            ans = max(ans,arr[i][j] + f3(i+1,j+1,n,arr));
        }

        return dp[i][j] = ans;
    }
    int maxCollectedFruits(vector<vector<int>>& arr) {
        int n = arr.size();
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans += arr[i][i];
            arr[i][i] = 0;
        }
        memset(dp,-1,sizeof dp);

        ans += f2(0,n-1,n,arr);
        memset(dp,-1,sizeof dp);
        ans += f3(n-1,0,n,arr);

        return (int)ans;

        
    }
};