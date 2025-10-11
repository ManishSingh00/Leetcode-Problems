#define ll long long int
class Solution {
public:
    unordered_map<ll,int>mp;
    ll dp[100005];
    ll f(int idx,vector<int>& power,int n){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];

        int j1 = upper_bound(power.begin(),power.end(),power[idx]) - power.begin();
        ll ans = f(j1,power,n);

        int j2 = upper_bound(power.begin(),power.end(),power[idx]+2) - power.begin();
        ans = max(ans,(1LL*power[idx]*mp[power[idx]]) + f(j2,power,n));

        return dp[idx] = ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(),power.end());
        int i = 0;
        while(i<n){
            int j=i;
            while(j<n && power[j] == power[i]){
                j++;
            }
            mp[power[i]] = j-i;
            i = j;
        }
        // for(auto x:mp){
        //     cout<<x.first<<x.second<<endl;
        // }

        memset(dp,-1,sizeof dp);

        return f(0,power,n);

    }
};