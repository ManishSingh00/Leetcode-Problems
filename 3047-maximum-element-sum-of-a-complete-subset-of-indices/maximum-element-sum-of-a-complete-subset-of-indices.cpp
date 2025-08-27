#define ll long long int
class Solution {
public:
    ll f(int n){
        unordered_map<int,int>mp;

        while(n%2 ==0){
            n = n/2;
            mp[2]++;
        }
        for(int i=3;i<=sqrt(n);i+=2){
            while(n % i == 0){
                n = n/i;
                mp[i]++;
            }
        }
        if(n>2) mp[n]++;

        ll ans = 1;
        for(auto x:mp){
            if(x.second % 2==1){
                ans *= x.first;
            }
        }
        return ans;

    }
    long long maximumSum(vector<int>& nums) {
        int m = nums.size();
        unordered_map<ll,vector<int>>mp;

        for(int i=1;i<=m;i++){
            ll val = f(i);
            mp[val].push_back(i);
        }
        ll ans = 0;
        for(auto it:mp){
            vector<int>temp = it.second;
            ll sum = 0;
            for(auto x: temp){
                sum += nums[x-1]; 
            }
            ans = max(ans,sum);
        }

        return ans;
    }
};