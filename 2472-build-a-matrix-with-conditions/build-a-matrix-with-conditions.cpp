class Solution {
public:
    vector<int>topoSort(int k,vector<vector<int>>& arr){
        vector<int>indeg(k+1,0);
        vector<vector<int>>gr(k+1);
        for(int i=0;i<arr.size();i++){
            gr[arr[i][0]].push_back(arr[i][1]);
            indeg[arr[i][1]]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;
        while(q.size()>0){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto v:gr[node]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()==k) return ans;
        else return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row_gr = topoSort(k,rowConditions);
        vector<int>col_gr = topoSort(k,colConditions);

        if(row_gr.size() == 0 || col_gr.size() == 0) return {};

        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[col_gr[i]]=i;
        }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            int column = mp[row_gr[i]];
            ans[i][column]  = row_gr[i];
        }
        return ans;

    }
};