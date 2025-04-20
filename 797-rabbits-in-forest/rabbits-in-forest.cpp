class Solution {
public:
    int numRabbits(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(arr[i] + 1) == mp.end()) ans += arr[i]+1;
            mp[arr[i]+1]++;
            if(mp[arr[i]+1]==arr[i]+1) mp.erase(mp[arr[i]+1]);
            
        }
        return ans;
    }
};