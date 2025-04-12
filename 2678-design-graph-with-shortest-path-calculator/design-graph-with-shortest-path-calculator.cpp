#define pp pair<int,int>
class Graph {
public:
    vector<vector<pair<int,int>>>gr;
    Graph(int n, vector<vector<int>>& edges) {
        gr.resize(n);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        gr[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pp,vector<pp>,greater<>>pq;
        vector<int>dist(gr.size(),INT_MAX);
        unordered_set<int>vis;
        dist[node1]=0;
        pq.push({0,node1});
        while(pq.size()>0){
            auto [wt,curr]=pq.top();
            pq.pop();
            if(vis.count(curr)!=0) continue;
            // if(curr==node2) return dist[node2];
            vis.insert(curr);
            for(auto v:gr[curr]){
                if(vis.count(v.first)==0 && dist[v.first]>dist[curr]+v.second){
                    dist[v.first]=dist[curr]+v.second;
                    pq.push({dist[curr]+v.second,v.first});
                }
            }
        }
        if(dist[node2]==INT_MAX) return -1;
        else return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */