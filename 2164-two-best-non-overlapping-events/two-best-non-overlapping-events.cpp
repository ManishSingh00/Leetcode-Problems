class Solution {
public:
    vector<int>start;
    int dp[100005][3];
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int f(int i,int k,int n,vector<vector<int>>& events){
        if(i >= n || k == 0){
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int ans = f(i+1,k,n,events);

        int j = upper_bound(start.begin(),start.end(),events[i][1]) - start.begin();
        ans = max(ans,events[i][2] + f(j,k-1,n,events));


        return dp[i][k] = ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end(),cmp);

        start.resize(n);
        for (int i = 0; i < n; i++) start[i] = events[i][0];

        memset(dp,-1,sizeof dp);
        return f(0,2,n,events);
    }
};