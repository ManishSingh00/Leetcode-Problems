class Solution {
public:
    int f(vector<int>& deg,vector<vector<int>>& gr,int n){ // Minimum height tree concept,, moving INWARDS
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }

        int cnt = n;
        int lev_cnt=0;
        while(cnt>2){
            int sz = q.size();
            cnt-=q.size();
            lev_cnt++;
            while(sz--){
                int node = q.front();
                q.pop();
                for(auto v:gr[node]){
                    deg[v]--;
                    if(deg[v]==1){
                        q.push(v);
                        // cnt--;
                    }
                }
            }
        }

        if(cnt==1) return 2*lev_cnt;
        else return 2*lev_cnt+1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>>gr1(n+1);
        vector<vector<int>>gr2(m+1);
        vector<int>deg1(n+1);
        vector<int>deg2(m+1);

        for(int i=0;i<n;i++){
            gr1[edges1[i][0]].push_back(edges1[i][1]);
            gr1[edges1[i][1]].push_back(edges1[i][0]);
            deg1[edges1[i][0]]++;
            deg1[edges1[i][1]]++;
        }

        for(int i=0;i<m;i++){
            gr2[edges2[i][0]].push_back(edges2[i][1]);
            gr2[edges2[i][1]].push_back(edges2[i][0]);
            deg2[edges2[i][0]]++;
            deg2[edges2[i][1]]++;
        }

        int x = f(deg1,gr1,n+1); // dia of tree1
        int y = f(deg2,gr2,m+1); // dia of tree 2;

        return max({x,y,(x+1)/2 + (y+1)/2 + 1});

    }
};