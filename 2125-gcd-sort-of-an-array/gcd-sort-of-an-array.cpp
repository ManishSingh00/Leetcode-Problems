class Solution {
public:
    vector<int>par;
    vector<int>sz;

    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }

    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b) return ;
        if(sz[a]>=sz[b]){
            sz[a]+=sz[b];
            par[b]=par[a];
        }
        else{
            sz[b]+=sz[a];
            par[a] = b;
        }
    }
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        par.resize(maxi+1);
        for(int i=0;i<=maxi;i++) par[i] = i;
        sz.resize(maxi+1,1);

        vector<int>nums2(nums.begin(),nums.end());
        sort(nums2.begin(),nums2.end());

        for(int i=0;i<n;i++){
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j == 0){ // if j is factor of nums[i], then gcd willl surely >1;
                    Union(nums[i],j);
                    Union(nums[i],nums[i]/j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(find(nums[i])!=find(nums2[i])) return false;
        }

        return true;

    }
};