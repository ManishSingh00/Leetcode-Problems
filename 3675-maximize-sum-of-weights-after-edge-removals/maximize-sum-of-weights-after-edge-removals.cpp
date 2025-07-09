#define ll long long 
class Solution {
public:
    vector<vector<pair<int,int>>>gr;
    ll dp[100005][2];

    static bool cmp(pair<ll,ll>& a, pair<ll,ll>& b){
        return (a.first-a.second) < (b.first-b.second);
    }
    ll f(int node,int par,bool par_remove,int k){
        if(dp[node][par_remove]!=-1) return dp[node][par_remove];
        int edges_to_remove = max(0,(int)gr[node].size()-k-par_remove);
        
        ll ans = 0;
        vector<pair<ll,ll>>arr;

        for(auto v:gr[node]){
            if(v.first!=par){
                ll not_remove = f(v.first,node,0,k) + v.second;
                ll remove = f(v.first,node,1,k);
                arr.push_back({not_remove,remove});
            }
        }

        sort(arr.begin(),arr.end(),cmp);
        for(int i=0;i<arr.size();i++){
            if(i<edges_to_remove){
                ans += arr[i].second; // taking remove
            }
            else{
                ans += max(arr[i].first,arr[i].second);
            }
        }
        return dp[node][par_remove] = ans;

    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        gr.resize(n);
        for(int i = 0;i<n-1;i++){
            gr[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            gr[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        memset(dp,-1,sizeof dp);
        return f(0,-1,0,k);
    }
};