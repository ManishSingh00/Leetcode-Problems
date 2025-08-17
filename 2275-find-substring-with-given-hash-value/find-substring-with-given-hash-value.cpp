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
    
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.length();
        hasher hs;
        hs.init(s,power,modulo);

        string ans = "";
        for(int i=0;i+k<=n;i++){
            int val = hs.getrevhash(i,i+k-1); // beacuse in this problem the hash is is defined in such a way thtthe exponent increases from left to right (lowest power on the left)., BUT, in above implementation there is highest power on the left, which is the opposite direction.
            if(val == hashValue){
                ans = s.substr(i,k);
                break;
            }
        }

        return ans;
    }
};