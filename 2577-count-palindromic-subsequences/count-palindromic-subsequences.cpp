#define mod 1000000007
class Solution {
public:
    int dp[10005][5];
    
    int f(int i, int j, vector<char>& temp, string &s) {
        if (j == 5) return 1;
        if (i >= s.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int x = 0, y = 0;
        if (s[i] == temp[j] || j == 2) x = f(i + 1, j + 1, temp, s);
        y = f(i + 1, j, temp, s);
        
        return dp[i][j] = (x + y) % mod;
    }
    
    int countPalindromes(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                memset(dp, -1, sizeof dp);
                char a=i+'0',b=j+'0';
                vector<char> temp = {a,b,'.',b,a};
                cnt = (cnt + f(0, 0, temp, s)) % mod;
            }
        }
        return cnt;
    }
};
