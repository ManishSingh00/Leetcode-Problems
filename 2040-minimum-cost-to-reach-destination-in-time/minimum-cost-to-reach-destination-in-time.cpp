#define pp tuple<int,int,int>
class Solution {
public:
    vector<vector<pair<int,int>>>gr;
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        int m = edges.size();
        gr.resize(n);
        for(int i=0;i<m;i++){
            int a=edges[i][0],b=edges[i][1],
            wt=edges[i][2];
            gr[a].push_back({b,wt});
            gr[b].push_back({a,wt});
        }
        priority_queue<pp,vector<pp>,greater<>>pq;
        pq.push({passingFees[0],0,0});// <fees,time,node>

        vector<vector<int>> minCost(n, vector<int>(maxTime + 1, INT_MAX)); // minCost[i][t] = min fee to reach node i at time t
        minCost[0][0]=passingFees[0];
        while(pq.size()>0){
            auto[fees,time,node]=pq.top();
            pq.pop();
            if(node==n-1) return fees;
            for(auto v:gr[node]){
                int new_time=time+v.second;
                if(new_time>maxTime) continue;
                if(minCost[v.first][new_time] > fees+passingFees[v.first]){
                    minCost[v.first][new_time]=fees+passingFees[v.first];
                    pq.push({fees+passingFees[v.first],new_time,v.first});
                }

            }
        }
        return -1;

       
       
    }
};