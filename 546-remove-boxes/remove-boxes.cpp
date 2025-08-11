class Solution {
public:
    int dp[101][101][101];
   int f(int l, int r, vector<int>& boxes, int prev_sz) {
    if (l > r) return 0;

    while (l< r && boxes[l] == boxes[l+1]) {
        l++;
        prev_sz++;
    }
    if (dp[l][r][prev_sz] != -1) return dp[l][r][prev_sz]; // adding above loop afetr this memo will lead to change in prev_sz, which is used in recursion staate, that's why it is wrtiiten above

    int ans = (prev_sz + 1) * (prev_sz + 1) + f(l + 1, r, boxes, 0);

    for (int k = l + 1; k <= r; k++) {
        if (boxes[k] == boxes[l]) {
            ans = max(ans,
                f(l + 1, k - 1, boxes, 0) +
                f(k, r, boxes, prev_sz + 1)
            );
        }
    }

    return dp[l][r][prev_sz] = ans;
}

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp,-1,sizeof dp);

        return f(0,n-1,boxes,0);
    }
};