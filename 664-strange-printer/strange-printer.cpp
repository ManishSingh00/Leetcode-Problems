class Solution {
public:
    int dp[101][101][101];
    int f(int l, int r, string& s, int prev_sz) {
        if (l > r) return 0;

        while (l< r && s[l] == s[l+1]) {
            l++;
            prev_sz++;
        }
        if (dp[l][r][prev_sz] != -1) return dp[l][r][prev_sz];

        int ans = 1 + f(l + 1, r, s, 0);

        for (int k = l + 1; k <= r; k++) {
            if (s[k] == s[l]) {
                ans = min(ans,f(l + 1, k - 1, s, 0) + f(k, r, s, prev_sz + 1));
            }
        }

        return dp[l][r][prev_sz] = ans;
    }
    int strangePrinter(string s) {
        int n = s.length();
        memset(dp,-1,sizeof dp);

        return f(0,n-1,s,0);
    }
};