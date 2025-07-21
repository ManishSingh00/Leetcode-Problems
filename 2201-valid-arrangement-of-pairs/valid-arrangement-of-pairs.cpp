#define ll long long int
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> indegree, outdegree;
    vector<int> ans;

    void dfs(int node){
        while(graph[node].size()>0){
            int temp = graph[node].back();
            graph[node].pop_back();
            dfs(temp);
        }
        ans.push_back(node);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        for(int i=0;i<n;i++){
            graph[pairs[i][0]].push_back(pairs[i][1]);
            indegree[pairs[i][1]]++;
            outdegree[pairs[i][0]]++;
        }

        int start = pairs[0][0];
        for(auto& x : graph){
            int a = x.first;
            if(outdegree[a] - indegree[a] == 1){
                start = a;
                break;
            }
        }

        dfs(start);
        reverse(ans.begin(),ans.end());
        vector<vector<int>>anss;

        for(int i=0;i<ans.size()-1;i++){
            int a = ans[i];
            int b = ans[i+1];
            anss.push_back({a,b});
        }


        return anss;

    }
};