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
    int longestDecomposition(string s) {
        int n = s.length();
        double_hash dh;
        dh.init(s);
        int ans = 0;

        // for(int i=0,j=n-1;i<n,j>=0;i++,j--){
        int i = 0,j = 0; 
        while(i<n){
            while(j<n){
                auto h1 = dh.gethash(i,j);
                ll key1 = 1LL * h1.first * 1000000021 + h1.second; 
                auto h2 = dh.gethash(n-j-1,n-i-1);
                ll key2 = 1LL * h2.first * 1000000021 + h2.second; 
                if(key1 == key2){
                    ans++;
                    cout<<i<<endl;
                    j++;
                    i=j;
                }
                else j++;
            }
        }
        return ans;
    }
};