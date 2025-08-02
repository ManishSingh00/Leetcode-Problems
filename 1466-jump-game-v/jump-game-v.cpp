class Solution {
public:
    int dp[1005];
    int f(int i,int d,vector<int>& arr,int n){
        if(dp[i]!=-1) return dp[i];
        int ans = 1;
    
        for(int j=i+1;j<=min(i+d,n-1);j++){
            if(arr[j] >= arr[i]) break;
            ans = max(ans,1+f(j,d,arr,n));
        }

        // cout<<"hello2"<<endl;

        for(int j=i-1;j>=max(i-d,0);j--){
            if(arr[j] >= arr[i]) break;
            ans = max(ans,1+f(j,d,arr,n));
        }

        // cout<<"hello3"<<endl;

        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        memset(dp,-1,sizeof dp);
       
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,f(i,d,arr,n));
            // cout<<"hello"<<endl;
        }
        return ans;
    }
};