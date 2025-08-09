class Solution {
public:
    double dp[205][205];
    double f(int a, int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1.0;
        if(b<=0) return 0.0;
        if(dp[a][b]>=0) return dp[a][b];

        double ans = 0.0;

        ans += f(a-4,b);
        ans += f(a-3,b-1);
        ans += f(a-2,b-2);
        ans += f(a-1,b-3);

        return dp[a][b] = 0.25*ans;
    }
    double soupServings(int n) {
        int m  = ceil(n/25.0);
        if (m >= 200) return 1.0;
        memset(dp,-1.0,sizeof dp);
        return f(m,m);
    }
};