class Solution {
public:
    unordered_map<int, int> dp;

    int f(int n) {
        if(n == 1) return 1;
        if(n == 0) return 0;
        if (dp.count(n)!=0) return dp[n];

        int ans1 = n%2 + 1 + f(n / 2);
        int ans2 = n%3 + 1 + f(n / 3);

        return dp[n] = min(ans1, ans2);
    }

    int minDays(int n) {
        return f(n);
    }
};
