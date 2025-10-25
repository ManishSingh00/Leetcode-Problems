class Solution {
public:
    int dp[1005][15];

    int f(int pos,int d_left,vector<int>& arr,int n){
        if(pos >= n) return 0;
        if(d_left == 1){
            return *max_element(arr.begin()+pos,arr.end());
        }
        if(dp[pos][d_left] != -1) return dp[pos][d_left];

        int ans = 1e9;
        int curr = 0;
        for(int i=pos;i<=n-d_left;i++){
            curr = max(curr,arr[i]);
            int aage_ka_ans = f(i+1,d_left-1,arr,n);
            ans = min(ans,curr+aage_ka_ans);
        }

        return dp[pos][d_left] = ans;
    }
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        memset(dp,-1,sizeof dp);
        int ans = f(0,d,arr,n);
        return ans==1e9?-1:ans;
    }
};