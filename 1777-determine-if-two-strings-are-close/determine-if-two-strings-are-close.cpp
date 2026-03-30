class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n = w1.length();
        int m = w2.length();
        if(n != m) return false;
        
        vector<int>cnt1(26,0), cnt2(26,0);

        for(int i=0;i<n;i++) cnt1[w1[i]-'a']++;
        for(int i=0;i<m;i++) cnt2[w2[i]-'a']++;

        for(int i=0;i<26;i++){
            if((cnt1[i] == 0 && cnt2[i]!=0) || (cnt1[i] != 0 && cnt2[i]==0)) return false;
        }

        sort(cnt1.begin(),cnt1.end());
        sort(cnt2.begin(),cnt2.end());

        return cnt1 == cnt2;
    }
};