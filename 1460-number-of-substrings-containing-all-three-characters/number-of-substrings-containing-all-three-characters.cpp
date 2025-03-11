class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int cnt=0;
        int ans=0;
        while(i<n){
            mp[s[i]]++;
            while(mp.size()==3){
                // cnt+=mp[s[j]];
                ans+=(n-i);
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
            i++;
        }
        return ans;
    }
};