class Solution {
public:
    int dp[1005];
    int f(int i,int n, vector<pair<int, int>>& players){
        if(i==0){
            return players[0].second;
        }
        if(dp[i]!=-1) return dp[i];
        int ans = players[i].second;
        for(int j=0;j<i;j++){
            if(players[j].second <= players[i].second) ans = max(ans,players[i].second+f(j,n,players));
        }
        return dp[i]= ans;
    }


    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i=0; i<n; i++) {
            players.push_back({ages[i],scores[i]});
        }
        sort(players.begin(), players.end());
        memset(dp,-1,sizeof dp);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,f(i,n,players));
        }
        return ans;
    }
};