#define ll long long

class Solution {
public:
    struct hasher{
    int n, _k, _p;
    vector<int> powk,base,rev;
    
    void init(string s,int k,int p){
        _k = k, _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        
        // precompute
        base[0] = 0;
        powk[0] = 1;
        for(int i=0;i<n;i++){
            int num = (s[i]-'a'+1 )%p;
            base[i+1] = (1LL *base[i] * k + num)%p;
            powk[i+1] = (1LL* k * powk[i]) %p;
        }
        
        // reverse
        rev.resize(n+1);
        rev[n] = 0;
        for(int i=n-1;i>=0;i--){
            int num = (s[i]-'a'+1 )%p;
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
    void init(string s){
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
 
    int n,m;
    double_hash ha,hb;
    vector<ll> intime,outtime;
    vector<vector<ll>> g;
    ll timer = 0;
    string st = "";

    void dfs(ll nn,ll pp,string &s){
        intime[nn] = timer;
        for(auto &v : g[nn]){
            if(v==pp){
                continue;
            }
            dfs(v,nn,s);
        }
        st += s[nn];
        outtime[nn] = timer;
        timer++;
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        ll n = parent.size();
        intime.resize(n,0);
        outtime.resize(n,0);
        g.resize(n);
        for(int i=0;i<n;i++){
            if(parent[i]!=-1){
                g[parent[i]].push_back(i);
            }
        }
        timer = 0;
        dfs(0,-1,s);
        ha.init(st);
        hb.init(st);
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            ll l = intime[i];
            ll r = outtime[i];
            if(ha.is_palin(l,r) && hb.is_palin(l,r)){
                ans[i] = true;
            }
        }
        return ans;
    }
};