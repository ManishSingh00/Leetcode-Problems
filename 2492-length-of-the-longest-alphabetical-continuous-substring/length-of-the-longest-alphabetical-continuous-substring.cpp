class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();

        int i = 0;
        int ans = 0;
        while(i<n){
            int j = i;
            int cnt = 0;
            bool flag = false;
            while(j<n && s[j]+1 == s[j+1]){
                j++;
                cnt++;
                flag = true;
            }
            ans = max(ans,cnt);
            if(flag == true) i = j;
            else i++;
        }
        return ans+1;
    }
};