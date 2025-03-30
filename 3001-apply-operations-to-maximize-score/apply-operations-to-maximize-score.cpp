#define ll long long int
#define MOD 1000000007 
class Solution {
public:
    ll binaryExponentiation(ll x, ll n) {
    ll result = 1;
    x = x % MOD;
    while (n > 0) {
        if (n & 1) { 
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD; 
        n >>= 1;
    }
    return result;
}
    vector<int> f(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
        
        return primes;
    }

    vector<ll> next_gr_ele(vector<int>& prime_score,int n){
        stack<ll>st;
        vector<ll>ans(n);
        ans[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && prime_score[st.top()]<=prime_score[i]) st.pop();
            if(st.size()>0) ans[i]=st.top();
            else ans[i]=n;
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<ans[i]<<endl;
        // }
        // cout<<"hello"<<endl;
        return ans;

    }
    vector<ll> pre_gr_ele(vector<int>& prime_score,int n){
        stack<ll>st;
        vector<ll>ans(n);
        ans[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && prime_score[st.top()]<prime_score[i]) st.pop();
            if(st.size()>0) ans[i]=st.top();
            else ans[i]=-1;
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<ans[i]<<endl;
        // }
        
        return ans;
    }
    void buildSPF(int maxVal, vector<int>& spf) {
        spf.resize(maxVal + 1);
        for (int i = 1; i <= maxVal; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }
    int getPrimeFactorCount(int x, const vector<int>& spf) {
        int cnt = 0;
        int last = -1;
        while (x > 1) {
            int factor = spf[x];
            if (factor != last) {
                cnt++;
                last = factor;
            }
            x /= factor;
        }
        return cnt;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1;
        for(auto x:nums) maxi=max(maxi,x);
        vector<int>prime=f(maxi);
        vector<int>prime_score(n);

        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for (int p : prime) {
        //         if(p>nums[i]) break;
        //         if(nums[i]%p==0) cnt++;
        //     }
        //     prime_score[i]=cnt;
        // }
        vector<int> spf;
        buildSPF(maxi, spf);
        
        // Use SPF to compute prime_score for each element in nums
        // vector<int> prime_score(n);
        for (int i = 0; i < n; i++) {
            prime_score[i] = getPrimeFactorCount(nums[i], spf);
        }

        vector<ll>nge=next_gr_ele(prime_score,n);
        vector<ll>pge=pre_gr_ele(prime_score,n);
        vector<ll>no_of_subarr(n);
        for(int i=0;i<n;i++){
            no_of_subarr[i] = (ll)(i-pge[i])*(ll)(nge[i]-i);
        }

        vector<pair<int,ll>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={nums[i],no_of_subarr[i]};
        }
        sort(temp.rbegin(),temp.rend());
        // for(int i=0;i<n;i++){
        //     cout<<temp[i].first<<" ";
        // }
        // cout<<endl;
        ll ans=1;
        for(int i=0;i<n;i++){
            ll move=min((ll)k,temp[i].second);
            k=k-move;
            ans = (ans*binaryExponentiation(temp[i].first,move))%MOD;
            if(k<=0) break;
            // cout<<move<<" " <<ans<<endl;
        }

        return ans;



    }
};