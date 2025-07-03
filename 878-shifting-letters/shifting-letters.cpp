class Solution {
public:
    string shiftingLetters(string s, vector<int>& arr) {
        int n = s.length();
        vector<long long>suff(n);
        suff[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]+arr[i];
        }

        for(int i=0;i<n;i++){
            long long shift = suff[i];

            s[i] = (s[i]-'a' + shift)%26 + 'a';
        }

        return s;
    }
};