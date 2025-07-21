class Solution {
public:
    unordered_map<string, vector<string>> graph;
    vector<string> ans;

    void dfs(string node){
        while(graph[node].size()>0){
            string temp = graph[node].back(); // here we are taking last element that's why reverse sorting is done
            graph[node].pop_back();
            dfs(temp);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            graph[arr[i][0]].push_back(arr[i][1]);
        }

        for (auto &v : graph)
            sort(v.second.rbegin(), v.second.rend());

        dfs("JFK");
        reverse(ans.begin(),ans.end());

        return ans;
    }
};