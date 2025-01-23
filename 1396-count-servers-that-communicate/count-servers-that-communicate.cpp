class Solution {
public:
    unordered_set<int>vis;
    vector<list<int>>graph;
    void dfs(int node,int& cnt){
        vis.insert(node);
        cnt++;
        for(auto neighbour: graph[node]){
            if(vis.count(neighbour)==0){
                dfs(neighbour,cnt);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        vector<vector<int>>coordinate;
        int no_of_ones=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    no_of_ones++;
                    coordinate.push_back({i,j});
                }
            }
        }
        int sz=coordinate.size();
        graph.resize(sz);
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                if(coordinate[i][0]==coordinate[j][0] || coordinate[i][1]==coordinate[j][1]){
                    graph[i].push_back(j);
                    graph[j].push_back(i); // bidirectional
                }
            }
        }

        vector<int>count_cc;
        int cc=0;
        for(int i=0;i<sz;i++){
            if(vis.count(i)==0){
                int cnt=0;
                dfs(i,cnt);
                cc++;
                count_cc.push_back(cnt);
            }
        }
        if(no_of_ones==cc) return 0;
        else if(cc==1) return no_of_ones;
        // else{
            int ans=0;
            int size=count_cc.size();
            for(int i=0;i<size;i++){
                if(count_cc[i]>1){
                    ans +=count_cc[i];
                }
            }
            return ans;
        // }
    }
};