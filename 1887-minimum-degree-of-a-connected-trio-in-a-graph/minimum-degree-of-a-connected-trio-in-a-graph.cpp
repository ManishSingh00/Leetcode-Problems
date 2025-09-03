class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>gr(n+1,vector<int>(n+1,0)); // here build it like adjacency matrix
        vector<int>deg(n+1,0);

        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]][edges[i][1]] = 1;
            gr[edges[i][1]][edges[i][0]] = 1;
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        int mini = INT_MAX;
        
        for(auto &v :edges){
            int a = v[0];
            int b = v[1];
            for(int i=1;i<=n;i++){
                if(gr[a][i] == 1 && gr[b][i] == 1){
                    mini = min(mini,deg[a]-2 + deg[b]-2 + deg[i]-2);
                }
            }
        }

        return mini==INT_MAX?-1:mini;
    }
};