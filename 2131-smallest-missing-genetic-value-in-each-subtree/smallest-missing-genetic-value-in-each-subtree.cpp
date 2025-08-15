class Solution {
public:
    vector<vector<int>>gr;
    unordered_set<int>gen_vis; // to mark visited genetics value
    vector<bool>node_vis; // to mark visited node 

    void bfs(int u,vector<int>& nums){
        queue<int>q;
        q.push(u);
        while(q.size()>0){
            int node = q.front();
            q.pop();
            if(node_vis[node] == true) continue;
            node_vis[node] = true;
            gen_vis.insert(nums[node]);
            for(auto v:gr[node]){
                q.push(v);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& par, vector<int>& nums) {
        int n = par.size();
        node_vis.resize(n,false);
        gr.resize(n);
        for(int i=0;i<n;i++){
            if(par[i]!=-1) gr[par[i]].push_back(i);
        }

        int pos = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                pos = i;
                break;
            }
        }
        vector<int>ans(n,1);

        if(pos == -1) return ans;

        int u = pos;
        int temp_val = 1;
        int prev = -1;
        while(u != -1){
            for(auto v:gr[u]){
                if(v!=prev) bfs(v,nums);
            }

            if(node_vis[u]==false){
                node_vis[u] = true;
                gen_vis.insert(nums[u]);
            }

            while(temp_val<=100005 && gen_vis.count(temp_val) != 0) temp_val++;

            ans[u] = temp_val;
            u = par[u];
            prev = u;

        }

        return ans;
    }
};