#define ll long long int
#define mod 1000000007
class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,vector<vector<int>>& arr, string& tar,int sz,int m){
        if(j == m){
            return 1;
        }
        if(i==sz) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans = 0;
        ans += (f(i+1,j,arr,tar,sz,m))%mod;
        if(arr[i][tar[j]-'a'] >= 1){
            int cnt = arr[i][tar[j]-'a'];
            // while(cnt--){ 
                ans += (1LL*cnt*f(i+1,j+1,arr,tar,sz,m))%mod;
            // }
        }

        return dp[i][j] = ans%mod;
    }
    int numWays(vector<string>& words, string tar) {
        int n = words.size();
        int sz = words[0].size();
        memset(dp,-1,sizeof dp);

        vector<vector<int>>arr(sz,vector<int>(26,0));
        for(int j=0;j<sz;j++){
            for(int i=0;i<n;i++){
                arr[j][words[i][j]-'a']++;
            }
        }

        return f(0,0,arr,tar,sz,tar.length());


    }
};