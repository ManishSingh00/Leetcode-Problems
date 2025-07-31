#define ll long long int
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(),coins.end());

        vector<ll>pref(n+1,0);
        // pref[0] = (coins[i][1]-coins[i][0]+1)*coins[i][2];
        vector<int>start(n),ends(n);
        // start[0] = coins[0][0];
        // end[0] = coins[0][1];

        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + 1LL*(coins[i][1] - coins[i][0] +1)*coins[i][2];
            start[i] = coins[i][0];
            ends[i] = coins[i][1];
        }

        ll final_ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            int init = coins[i][0];
            int last_idx = init+k-1;
            int temp = lower_bound(ends.begin(),ends.end(),last_idx) - ends.begin();

            ll ans = pref[temp] - pref[i];
            if(temp<n) ans += 1LL*max(0,last_idx - coins[temp][0]+1)*coins[temp][2];
            final_ans = max(final_ans,ans);
        }

        for(int i=0;i<n;i++){
            int init = coins[i][1];
            int last_idx = init-k+1;
            int temp = lower_bound(start.begin(),start.end(),last_idx) - start.begin();

            ll ans = pref[i+1] - pref[temp];
            if(temp>0) ans += 1LL*max(0,coins[temp-1][1] - last_idx + 1)*coins[temp-1][2];
            final_ans = max(final_ans,ans);
        }

        return final_ans;

    }
};