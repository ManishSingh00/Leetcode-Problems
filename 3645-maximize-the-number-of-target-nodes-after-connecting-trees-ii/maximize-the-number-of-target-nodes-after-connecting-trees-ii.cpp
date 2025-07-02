class Solution {
public:
    void dfs(int u, int p, int d,vector<vector<int>>& tree,vector<int>& depth){
        depth[u] = d&1; // marking nodes as 0 and 1
        for (int v : tree[u]){
            if (v != p){
                dfs(v, u, d + 1, tree, depth);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size();
        int n2 = edges2.size();

        vector<vector<int>>gr1(n1+1);
        vector<vector<int>>gr2(n2+1);

        for(int i=0;i<n1;i++){
            gr1[edges1[i][0]].push_back(edges1[i][1]);
            gr1[edges1[i][1]].push_back(edges1[i][0]);
        }

        for(int i=0;i<n2;i++){
            gr2[edges2[i][0]].push_back(edges2[i][1]);
            gr2[edges2[i][1]].push_back(edges2[i][0]);
        }

        vector<int>dist1(n1+1),dist2(n2+1);
        dfs(0,-1,0,gr1,dist1);
        dfs(0,-1,0,gr2,dist2);

        int even1=0,odd1=0,even2=0,odd2=0;

        for(auto x:dist1){
            if(x==0) even1++;
            else odd1++;
        }
        for(auto x:dist2){
            if(x==0) even2++;
            else odd2++;
        }

        int maxi = max(even2,odd2);
        vector<int>ans(n1+1);

        for(int i=0;i<n1+1;i++){
            if(dist1[i]==0){
                ans[i] = even1+maxi;
            }
            else ans[i] = odd1+maxi;
        }


        return ans;
    }
};