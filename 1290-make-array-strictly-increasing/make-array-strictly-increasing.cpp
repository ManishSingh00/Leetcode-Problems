class Solution {
public:
    int n,m;
    map<pair<int,int>,int>dp;
    int f(int idx,int prev,vector<int>& arr1,vector<int>& arr2){
        if(idx == n){
            return 0;
        }

        if(dp.find({idx,prev}) != dp.end()) return dp[{idx,prev}];

        int ans = 1e5;
        int i = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();

        if(i<m) ans = 1 + f(idx+1,arr2[i],arr1,arr2);
        if(arr1[idx] > prev) ans = min(ans, f(idx+1,arr1[idx],arr1,arr2));

        return dp[{idx,prev}] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n = arr1.size();
        m = arr2.size();
        sort(arr2.begin(),arr2.end());

        int ans = f(0,-1,arr1,arr2);

        return ans>=1e5?-1:ans;
    }
};