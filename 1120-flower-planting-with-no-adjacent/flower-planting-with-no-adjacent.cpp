class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>gr(n+1);
        vector<bool>vis(n+1,false);

        for(auto v:paths){
            gr[v[0]].push_back(v[1]);
            gr[v[1]].push_back(v[0]);
        }

        vector<int>ans(n+1);

        for(int i=1;i<=n;i++){
            if(vis[i] == false){
                queue<int>q;
                q.push(i);
                vis[i] = false;
                ans[i] = 1;

                while(q.size()>0){
                    int node = q.front();
                    q.pop();

                    for(auto v :gr[node]){
                        if(vis[v] == false){
                            vis[v] = true;
                            vector<int>clr(5,0);
                            for(auto x:gr[v]){
                                // cout<<x<<" "<<ans[x]<<endl;
                                clr[ans[x]] = 1;
                            }

                            for(int k=1;k<5;k++){
                                if(clr[k]==0){
                                    ans[v] = k;
                                    break;
                                }
                            }
                            q.push(v);
                        }
                    }
                }
            }
        }
        vector<int>temp;
        for(int i=1;i<=n;i++){
            temp.push_back(ans[i]);
        }
        return temp;
    }
};