#define pp pair<int,pair<int,int>>
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    vector<int> maxPoints(vector<vector<int>>& arr, vector<int>& queries) {
        int m=arr.size();
        int n=arr[0].size();
        int k=queries.size();
        vector<int>ans(k);
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<pair<int,int>>q_map;// store queuy order and their index
        for(int i=0;i<k;i++){
            q_map.push_back({queries[i],i});
        }
        sort(q_map.begin(),q_map.end());
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({arr[0][0],{0,0}});
        vis[0][0] = true;
        int pts = 0;

        for (auto x : q_map) {
           int check_val=x.first;
           int idx=x.second;
           while(pq.size()>0 && pq.top().first<check_val){
                // int val=pq.top().first;
                int r=pq.top().second.first;
                int c=pq.top().second.second;
                pq.pop();
                pts++;
                for(int k=0;k<4;k++){
                    int nr=r+dx[k],nc=c+dy[k];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==false ){
                        pq.push({arr[nr][nc],{nr,nc}});
                        vis[nr][nc]=true;
                        // pts++;
                    }
                }
            }
           ans[idx]=pts;
        }

        return ans;
        
    }
};