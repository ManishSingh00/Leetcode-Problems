class Solution {
public:
    int dp[10005];
    int f(int idx,vector<pair<int,int>>& intervals,int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int ans = 1e5;
        for(int i=0;i<n+1;i++){
            if(intervals[i].first<=idx && intervals[i].second>idx){
                ans = min(ans,1+f(intervals[i].second,intervals,n));
            }
        }

        return dp[idx]= ans;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i <= n; ++i) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.push_back({start, end});
        }
        sort(intervals.begin(), intervals.end());

        memset(dp,-1,sizeof dp);
        int res = f(0, intervals, n);
        return res >= 1e5 ? -1 : res;
    }
};