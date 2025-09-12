class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int  n = s.length();
        vector<int>arr(26,0);
        for(int i=0;i<k;i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a'] == k && i<n && s[i+1] != s[i]) return true; 
        }   

        int i = k;
        // cout<<"true";
        while(i<n){
            arr[s[i]-'a']++;
            arr[s[i-k] - 'a']--;
            if(arr[s[i]-'a'] == k && i<n && s[i+1] != s[i] && s[i-k] != s[i]) return true;
            i++;
        }

        return false;

    }
};