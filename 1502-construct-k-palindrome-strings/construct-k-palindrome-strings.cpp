class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k>n) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int cnt_odd=0;
        for(auto x:mp){
            if(x.second%2!=0) cnt_odd++;
        }
        if(cnt_odd>k) return false;
        else return true; 
    }
};