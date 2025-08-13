class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int src, int tar) {
        int n = r.size();
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            for(auto x:r[i]){
                mp[x].push_back(i);
            }
        }

        queue<pair<int,int>>q;
        q.push({src,0});  //{,buses}

        unordered_set<int>vis1; // to mark stops
        vector<int>vis2(n,false); // to mark routes

        vis1.insert(src);
        while(q.size()>0){
            auto [node,buses] = q.front();
            q.pop();

            if(node==tar) return buses;

            for(auto ids : mp[node]){
                if(vis2[ids] == true) continue;
                vis2[ids] = true;

                for(auto nxtstop:r[ids]){
                    if(vis1.count(nxtstop) == 0){
                        vis1.insert(nxtstop);
                        q.push({nxtstop,buses+1});
                    }
                }
            }
        }

        return -1;
    }
};