#define ll long long 
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.length();
        vector<ll> preL(n+1,0), preLC(n+1,0), sufT(n+1,0), sufCT(n+1,0);

        for(int i = 0; i < n; i++) {
            preL[i+1] = preL[i];
            preLC[i+1] = preLC[i];
            if(s[i] == 'L') preL[i+1]++;
            if(s[i] == 'C') preLC[i+1] += preL[i];
        }

        for(int i = n-1; i >= 0; i--) {
            sufT[i] = sufT[i+1];
            sufCT[i] = sufCT[i+1];
            if(s[i] == 'T') sufT[i]++;
            if(s[i] == 'C') sufCT[i] += sufT[i+1];
        }
        ll base = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'T') {
                base += preLC[i];
            }
        }


        ll final_ans = 0;
        for(int i = 0; i <= n; i++) {
            ll gainL = sufCT[i];
            ll gainC = preL[i] * sufT[i];
            ll gainT = preLC[i];

            final_ans = max({final_ans, base + gainL, base + gainC, base + gainT});
        }

        return final_ans;
    }
};
