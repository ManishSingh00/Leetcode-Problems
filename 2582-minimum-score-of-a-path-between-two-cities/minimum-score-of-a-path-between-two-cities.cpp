class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<list<pair<int,int>>>gr(n+1);
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0],b=roads[i][1],c=roads[i][2];
            gr[a].push_back({b,c});
            gr[b].push_back({a,c});
        }
        int ans = INT_MAX;
        queue<pair<int,int>>q;
        q.push({1,INT_MAX});
        unordered_set<int>vis;
        vis.insert(1);
        while(q.size()>0){
            auto [curr,wt] = q.front();
            q.pop();
            for(auto v:gr[curr]){
                ans = min(ans,v.second);
                if(vis.count(v.first)==0){
                    vis.insert(v.first);
                    q.push({v.first,v.second});
                }
            }
        }
        return ans;
    }
};