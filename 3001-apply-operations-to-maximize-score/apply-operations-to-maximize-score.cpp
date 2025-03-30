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
    


    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prime_score(n);

        for(int i=0;i<n;i++){
            int num=nums[i];
            int cnt=0;
            for(int fact=2;fact<=sqrt(num);fact++){
                if(num%fact==0){
                    cnt++;
                    while(num%fact==0){
                        num/=fact;
                    }
                }
            }
            if(num>=2) cnt++; //in this case nums itself a prime factor
            prime_score[i]=cnt;
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