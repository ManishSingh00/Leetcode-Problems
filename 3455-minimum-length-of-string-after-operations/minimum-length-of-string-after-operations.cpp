class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }

        for(int i=0;i<n;i++){
            if(arr[s[i]-'a'] >= 3) arr[s[i]-'a']-=2;
        }
        int cnt = 0;
        for(int i = 0;i<26;i++){
            cnt+=arr[i];
        }
        return cnt;
    }
};