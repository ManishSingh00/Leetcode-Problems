class Solution {
public:
    unordered_map<int,vector<int>>mp;
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }    
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,false);
        vis[0]= true;
        while(q.size()>0){
            int node = q.front().first;
            int step = q.front().second;
            q.pop();

            if(node == n-1) return step;

            if(node-1>=0 && vis[node-1]==false){
                vis[node-1]=true;
                q.push({node-1,step+1});
            }
            if(node+1 <n && vis[node+1]==false){
                vis[node+1]=true;
                q.push({node+1,step+1});
            }

            vector<int> temp = mp[arr[node]];
            mp[arr[node]].clear();
            for(int j=0;j<temp.size();j++){

                if(vis[temp[j]] == false){
                    vis[temp[j]] = true;
                    q.push({temp[j],step+1});
                }
            }

        }

        return -1;
    }
};