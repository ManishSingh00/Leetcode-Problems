class Solution {
public:
    bool canReach(string s, int mini, int maxi) {
        int n = s.length();
        vector<bool>vis(n,false);
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0] = true;
        int farthest = 0;
        while(q.size()>0){
            int idx = q.front().first;
            int step = q.front().second;
            q.pop();

            if(idx == n-1) return true;
             for (int next = max(idx + mini, farthest + 1); next <= min(idx + maxi, n - 1); ++next) {
                if (s[next] == '0' && !vis[next]) {
                    vis[next] = true;
                    q.push({next,step+1});
                }
            }
            
            farthest = max(farthest, idx + maxi);
        }

        return false;
    }
};