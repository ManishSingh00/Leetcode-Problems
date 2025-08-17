#define ll long long int
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
    string longestDupSubstring(string s) {
        int n = s.length();
        double_hash dh;
        dh.init(s);

        int lo = 1;
        int hi = n-1;
        int max_len = -1;
        int start = -1;

        while(lo <= hi){
            int mid = (lo+hi)/2;
            bool flag = false;
            unordered_map<ll,int>mp;
            for(int i=0;i+mid <= n;i++){
                auto h = dh.gethash(i, i + mid - 1);
                ll key = 1LL * h.first * 1000000021 + h.second; 

                if(mp.find(key)!=mp.end()){
                    flag = true;
                    start = i;
                    break;
                }
                mp[key] = i; 
            }
            if(flag == true){
                max_len = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        if(start == -1) return "";
        else return s.substr(start,max_len);
    }
};