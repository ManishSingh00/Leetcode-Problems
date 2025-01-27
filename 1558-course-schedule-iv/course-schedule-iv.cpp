class Solution {
public:
    vector<list<int>>gr;
    void add_edge(int n,vector<vector<int>>& arr){
        for(int i=0;i<arr.size();i++){
            gr[arr[i][1]].push_back(arr[i][0]);
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& arr, vector<vector<int>>& queries) {
        gr.resize(n);
        add_edge(n,arr);
        vector<vector<bool>>ans(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            queue<int>q;
            unordered_set<int>vis;
            q.push(i);
            vis.insert(i);
            while(q.size()>0){
                int x=q.front();
                q.pop();
                for(auto it:gr[x]){
                    if(vis.count(it)==0){
                        vis.insert(it);
                        q.push(it);
                        ans[i][it]=true;
                    }
                }
            }

        }
        // cout<<"hello1"<<endl;
        vector<bool>final_ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            final_ans[i]=ans[y][x];
        }
        return final_ans;
    }
};