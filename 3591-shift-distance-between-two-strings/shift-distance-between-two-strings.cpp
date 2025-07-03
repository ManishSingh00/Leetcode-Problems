class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& next, vector<int>& prev) {
        int n = s.length();

        long long ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]==t[i]) continue;

            // forward move
            long long cost1 = 0;
            char temp = s[i];
            while(temp!=t[i]){
                cost1 += next[temp -'a'];
                temp = (temp-'a'+1)%26 +'a';
            }

            long long cost2 = 0;
            temp = s[i];
            while(temp!=t[i]){
                cost2 += prev[temp-'a'];
                temp = (temp-'a' - 1 + 26)%26 + 'a';
            }
            ans += min(cost1,cost2);
        }
        return ans;
    }
};