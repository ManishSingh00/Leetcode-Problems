#define ll long long int
class Solution {
public:
     struct hasher{
        int n, _k, _p;
        vector<int> powk,base,rev;
        
        void init(vector<int>& s,int k,int p){
            _k = k, _p = p;
            n = s.size();
            powk.resize(n+1);
            base.resize(n+1);
            
            // precompute
            base[0] = 0;
            powk[0] = 1;
            for(int i=0;i<n;i++){
                int num = (s[i]+1 )%p;
                base[i+1] = (1LL *base[i] * k + num)%p;
                powk[i+1] = (1LL* k * powk[i]) %p;
            }
            
            // reverse
            rev.resize(n+1);
            rev[n] = 0;
            for(int i=n-1;i>=0;i--){
                int num = (s[i]+1 )%p;
                rev[i] = (1LL *rev[i+1] * k + num)%p;
            }
        }  
        int gethash(int l,int r){ // 0 index
            int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
            return (ans+_p)%_p;
        }
        // reverse hash
        int getrevhash(int l,int r){
            int ans = (rev[l] - 1LL *rev[r+1]*powk[(r-l+1)])%_p;
            return (ans+_p)%_p;
        }
    };
    
    struct double_hash{
        hasher a,b;
        void init(vector<int>& s){
            a.init(s,37,1000000021);
            b.init(s,39,1000000009);
        }
        pair<int,int> gethash(int l,int r){
            return {a.gethash(l,r),b.gethash(l,r)};
        }
        pair<int,int> getrevhash(int l,int r){
            return {a.getrevhash(l,r),b.getrevhash(l,r)};
        }
        bool is_palin(int l,int r){
            return gethash(l,r) == getrevhash(l,r);
        }
    };
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int m = paths.size();
        int hi = 0;
        for(auto x:paths){
            hi = max(hi,(int)x.size());
        }
        int lo = 1;
        int max_len = 0;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            unordered_set<ll>mp;

            double_hash dh;  // processing of fisrt path
            dh.init(paths[0]);
            for(int j=0;j+mid<=paths[0].size();j++){
                auto h = dh.gethash(j,j+mid-1);
                ll key = 1LL * h.first * 1000000021 + h.second;
                mp.insert(key);
            }

            for(int j=1;j<m;j++){
                double_hash dh;
                dh.init(paths[j]);
                unordered_set<ll>temp;
                for(int k=0;k+mid<=paths[j].size();k++){
                    auto h = dh.gethash(k,k+mid-1);
                    ll key = 1LL * h.first * 1000000021 + h.second;
                    if(mp.count(key)!=0) temp.insert(key);
                }
                mp = temp;
            }
            if(mp.size()>0){
                max_len = mid;
                lo = mid+1;
            }
            else hi = mid-1;

        }
        return max_len;

    }
};