class Solution {
public:
    int find(vector<int> &parent,int x){
        if(parent[x]==x) return x;
        else return parent[x]=find(parent,parent[x]);
    }
    void Union(vector<int> &parent,vector<int>&rank,int a,int b,vector<int>& cost,int wt){
        a=find(parent,a);
        b=find(parent,b);

        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
            cost[a] &= cost[b];
            cost[a] &= wt;
        }
        else {
            rank[b]++;
            parent[a]=b;
            cost[b] &= cost[a];
            cost[b] &= wt;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int m=edges.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>cost(n,-1);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0],b=edges[i][1],wt=edges[i][2];
            if(cost[a]==-1) cost[a]=wt;
            if(cost[b]==-1) cost[b]=wt;
            Union(parent,rank,a,b,cost,wt);
            // cost[a]&=wt;
            // cost[b]&=wt;
        }
        vector<int>ans;
        for(int i=0;i<query.size();i++){
            int a=query[i][0],b=query[i][1];
           if(find(parent,a)==find(parent,b)) ans.push_back(cost[find(parent,a)]);
            else ans.push_back(-1);
        }
        return ans;
    }
};