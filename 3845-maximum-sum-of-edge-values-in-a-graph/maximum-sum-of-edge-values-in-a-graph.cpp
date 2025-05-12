class Solution {
public:
    vector<vector<int>>gr;

    bool dfs(int src,int par,unordered_set<int>& vis,int & cnt){
        vis.insert(src);
        cnt++;
        for(auto v:gr[src]){
            if(vis.count(v)==0){
                if(dfs(v,src,vis,cnt)==true) return true;
            }
            else if(v!=par){
                return true;
            }
        }

        return false;
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        gr.resize(n);
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }

        vector<pair<int,int>>cycle;
        vector<pair<int,int>>non_cycle;

        // run  dfs for cycle finding
        unordered_set<int>vis;
        for(int i=0;i<n;i++){
            if(vis.count(i)==0){
                int cnt=0;
                if(dfs(i,-1,vis,cnt)==true){
                    cycle.push_back({cnt,i});
                }
                else{
                    non_cycle.push_back({cnt,i});
                }
            }
        }
        //sort to process bigger cycle first or bigger chain first
        sort(cycle.rbegin(),cycle.rend());
        sort(non_cycle.rbegin(),non_cycle.rend());

        int val = n;
        long long ans=0;

        for(int i=0;i<cycle.size();i++){
            int len = cycle[i].first;
            vector<int>arr(len);
            int start = val - len + 1;
            for(int i=0;i<len/2;i++){
                arr[i] = start;
                start++;
                arr[len-i-1]=start;
                start++;
            }
            if(len % 2 != 0) arr[len/2] = start; // middle ele in case of odd lenght
            for(int i=1;i<len;i++){
                ans += (1LL*arr[i]*arr[i-1]);
            }   
            ans += (1LL*arr.back()*arr.front());
            val = val - len;
        }

        // now process chains
        for(int i=0;i<non_cycle.size();i++){
            int len = non_cycle[i].first;
            vector<int>arr(len);
            int start = val - len + 1;
            for(int i=0;i<len/2;i++){
                arr[i] = start;
                start++;
                arr[len-i-1]=start;
                start++;
            }
            if(len % 2 != 0) arr[len/2] = start;
            for(int i=1;i<len;i++){
                ans += (1LL*arr[i]*arr[i-1]);
            }   
            val = val - len;
        }
        return ans;
    }
};