class Solution {
public:
    vector<int>par;
    vector<int>sz;
    int find(int x,vector<int>& nums){
        if(x == par[x]) return x;
        else return par[x] = find(par[x],nums);
    }

    void Union(int a,int b,vector<int>& nums){
        a = find(a,nums);
        b = find(b,nums);
        if(par[a] == par[b]) return;
        if(sz[a]>=sz[b]){
            sz[a]+=sz[b];
            par[b] = par[a];
        }
        else{
            sz[b] += sz[a];
            par[a] = par[b];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        par.resize(maxi+1);
        sz.resize(maxi+1,1);
        for(int i=0;i<=maxi;i++) par[i] = i;

        for(auto v:nums){
            int x = v;
            for(int fact =2;fact<=sqrt(v);fact++){
                if(x%fact == 0){
                    Union(v,fact,nums);
                    while(x%fact == 0) x/=fact;
                }
            }
            if(x>1) Union(v,x,nums);
        }
        int ans = -1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int root = find(nums[i],nums);
            mp[root]++;
            ans = max(ans,mp[root]);
        }

        return ans;
    }
};