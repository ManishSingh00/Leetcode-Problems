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
    bool isPrefix(double_hash& dh, int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if (len1 > len2) return false;
        return dh.gethash(l1, r1) == dh.gethash(l2, l2 + len1 - 1);
    }
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        string s = "";
        for (int num : nums) {
            s += char('a' + num);
        }

        double_hash dh;
        dh.init(s);
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                bool cond1 = isPrefix(dh, 0, i - 1, i, j - 1);
                bool cond2 = isPrefix(dh, i, j - 1, j, n - 1);
                if (cond1 || cond2) {
                    count++;
                }
            }
        }

        return count;
    }
};