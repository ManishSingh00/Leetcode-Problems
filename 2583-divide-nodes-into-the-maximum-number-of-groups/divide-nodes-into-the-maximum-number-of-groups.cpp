class Solution {
public:
    vector<list<int>>graph;
    void add_edge(vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
    bool check_bipartite(vector<int>&arr,int src,vector<int>& component){
        queue<int>q;
        q.push(src);
        arr[src]=0;
        component.push_back(src);
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(auto neighbour:graph[curr]){
                if(arr[neighbour]==-1){
                    if(arr[curr]==0) arr[neighbour]=1;
                    if(arr[curr]==1) arr[neighbour]=0;
                    q.push(neighbour);
                    component.push_back(neighbour);
                }
                else if(arr[curr]==arr[neighbour]) {
                    return false;
                }
            }

        }
        return true;
    }
    int find_max_size(vector<int>& component,int n){
        int ans =0;
        for(auto i:component){
            queue<int>q;
            q.push(i);
            vector<int>dist(n+1,-1);
            unordered_set<int>st;
            dist[i]=0;
            while(q.size()>0){
                int node=q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(dist[it]==-1){
                        dist[it]=1+dist[node];
                        q.push(it);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(dist[i]!=-1) st.insert(dist[i]);
            }
            int sz=st.size();
            ans = max(ans ,sz);
        }
        return ans;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        graph.resize(n+1);
        add_edge(edges);
        // bipartite check
        vector<int>arr(n+1,-1);
        int final_ans=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==-1){
                vector<int>component;
               if(check_bipartite(arr,i,component)==false){
                    return -1;
               }
                final_ans += find_max_size(component,n);
            }
        }
        return final_ans;
        
    }
};