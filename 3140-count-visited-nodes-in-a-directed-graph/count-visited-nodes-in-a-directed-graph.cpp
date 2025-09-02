class Solution {
public:
    vector<vector<int>>gr;
    vector<int>state;
    vector<int>dp;
    void dfs(int node){
        state[node] = 1; // mark as visiting
        for(auto v:gr[node]){
            if(state[v] == 0){
                dfs(v);
                if(dp[node] == -1) dp[node] = 1 + dp[v];
            }
            else if(state[v] == 1){  // cycle detected
                int u = v;
                int len = 1; // finding cycle leength
                u = gr[u][0];
                while(u != v){
                    u = gr[u][0];
                    len++;
                }

                u = v;
                dp[u] = len;
                u = gr[u][0];  // pputting that length to all nodes present in that cycle
                while(u != v){
                    dp[u] = len;
                    u = gr[u][0];
                }

                if(dp[node] == -1) dp[node] = 1+dp[v];

            }
            else if(state[v] == 2){
                dp[node] = 1 + dp[v];
            }
        }
        state[node] = 2;

    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        gr.resize(n);
        state.resize(n,0);
        dp.resize(n,-1);
        
        for(int i=0;i<n;i++){
            gr[i].push_back(edges[i]);
        }

        for(int i=0;i<n;i++){
            if(state[i] == 0){
                dfs(i);
            }
        }

        return dp;
    }
};