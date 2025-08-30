class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>gr(n);
        vector<int>indeg(n,0);

        for(int i=0;i<edges.size();i++){
            int a = edges[i][0], b=edges[i][1];
            gr[a].push_back(b);
            indeg[b]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<vector<int>>dp(n,vector<int>(26,0));
        // dp[u][c] = maximum number of nodes of color c along any path ending at u.
        // While processing nodes in topological order, update children based on parent dp.
        int cnt = 0;
        int ans = -1;
        while(q.size()>0){
            int node = q.front();
            q.pop();
            cnt++;

            dp[node][colors[node]-'a']++;
            ans = max(ans,dp[node][colors[node]-'a']);

            for(auto v:gr[node]){
                for(int i=0;i<26;i++){
                    dp[v][i] = max(dp[v][i], dp[node][i]);
                }
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }

        }

        if(cnt < n) return -1;  // cycle is present
        return ans;
        
    }
};