#define mod 1000000007
class Solution {
public:
    int countPairs(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int cnt=0;
        mp[arr[0]]++;
        for(int i=1;i<n;i++){
            for(int p=0;p<31;p++){
                int to_find=(int)pow(2,p)-arr[i];
                if(mp.find(to_find)!=mp.end()){
                    cnt=(cnt+mp[to_find])%mod;
                }
            }
            mp[arr[i]]++;
        }
        return cnt;
    }
};