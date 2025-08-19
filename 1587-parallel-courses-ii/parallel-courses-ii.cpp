class Solution {
public:
    vector<vector<int>>gr;
    int dp[1<<15];
    int f(int mask,int n,int k){
        if(mask == ((1<<n)-1)) return 0;
        if(dp[mask] != -1) return dp[mask];

        vector<int>indeg(n+1,0);
        for(int i=1;i<=n;i++){
            if(mask & (1<<(i-1))) continue; // instead of i-1 , one option is to solve the problem in 0-indexed
            for(auto v:gr[i]){
                indeg[v]++;
            }
        }

        int temp_mask = 0;

        for(int i=1;i<=n;i++){
            if(indeg[i] == 0 && !(mask&(1<<(i-1)))){
                temp_mask |= (1<<(i-1));
            }
        }

        int val = __builtin_popcount(temp_mask);
        int ans = INT_MAX;
        if(val<=k){
            ans = min(ans,1+f(mask|temp_mask,n,k));
        } 
        else{ // when val>k
            for(int sub = temp_mask; sub; sub = (sub-1) & temp_mask) { // this is VERY IMP STEP, iterating over SUBMASK of temp_mask
                if(__builtin_popcount(sub) <= k) {
                    ans = min(ans, 1 + f(mask | sub,n,k));
                }
            }
        }

        return dp[mask] = ans;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        gr.resize(n+1);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<relations.size();i++){
            gr[relations[i][0]].push_back(relations[i][1]);
        }
        return f(0,n,k);
    }
};