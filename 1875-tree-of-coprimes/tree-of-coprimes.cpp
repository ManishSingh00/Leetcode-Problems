class Solution {
public:
    vector<vector<int>>gr;
    vector<vector<bool>>co_prime;
    vector<int>last; // last[val] = node index of deepest ancestor with value = val
    vector<int>depth;
    vector<int>ans;

    void dfs(int node,int parent,int dep,vector<int>& nums){
        depth[node] = dep;

        int max_depth = -1;
        int bestNode = -1;
        for(int i=1;i<=50;i++){
            if(co_prime[nums[node]][i] == true && last[i] != -1){
                int x = last[i];
                if(depth[x] > max_depth){
                    max_depth = depth[x];
                    bestNode = x;
                }
            }
        }
        ans[node] = bestNode;

        int prev = last[nums[node]];
        last[nums[node]] = node;

        for(auto v:gr[node]){
            if(v!=parent){
                dfs(v,node,dep+1,nums);
            }
        }
        last[nums[node]] = prev;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        gr.resize(n);
        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }

        co_prime.resize(51,vector<bool>(51,false));
        last.resize(51,-1);
        depth.resize(n,0);

        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(gcd(i,j)==1){
                    co_prime[i][j] = true;
                }
            }
        }

        ans.resize(n,-1);
        dfs(0,-1,1,nums);
        return ans;

    }
};